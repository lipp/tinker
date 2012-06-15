local socket = require'socket'
local pack = require'pack'
local pairs = pairs
local ipairs = ipairs
local assert = assert
local error = error
local print = print
local string = string
local select = select
local require = require
local type = type
local _G = _G

module('tinker')

-- stackid,funcid,length
local packet_header = 'bbH'
-- uuid,name,stackid,is_new
local enum_format = 'A8A40bb'
local enum_req_funcid = 0xfe
local enum_resp_funcid = 0xfd
local enum_stackid = 0
local enum_resp_length = 50 -- without header size

local send_request = 
   function(sock,stackid,funcid,payload)
      payload = payload or ''
      local len = 4 + #payload 
      local req = packet_header:pack(stackid,funcid,len)
      assert(sock:send(req..payload))
   end

local recv_response = 
   function(sock)
      local resp = sock:receive(4)
      if resp then
         local _,rstackid,rfuncid,rlen = resp:unpack(packet_header)
         return rstackid,rfuncid,sock:receive(rlen-4)
      end
   end

local ipcon = 
   function(ip,port)
      local brickd_call_sock
      local brickd_event_sock
      local devs
      
      ip = ip or 'localhost'
      port = port or 4223
      local brickd_call_sock = socket.connect(ip,port)
      local brickd_event_sock
      
      local call = 
         function(stackid,method,...)
            local arguments
            if method.ins then
               if method.format_ins then
                  arguments = method.ins:pack(method.format_ins(...))
               else
                  arguments = method.ins:pack(...)
               end
            end
            send_request(brickd_call_sock,stackid,method.funcid,arguments)
            if method.outs then
               local rstackid,rfuncid,resp = recv_response(brickd_call_sock)
               assert(stackid==rstackid,funcid==rfuncid)
               if method.format_outs then
                  return method.format_outs(select(2,resp:unpack(method.outs)))
               else
                  return select(2,resp:unpack(method.outs))
               end
            end
         end

      local enumerate_callback
      local devs = {}
      
      local enumerate =
         function(_,arg)
            if type(arg) == 'function' then
               enumerate_callback = arg
               if not brickd_event_sock then
                  brickd_event_sock = socket.connect(ip,port)
               end
               local trigger_enum = 
                  function()
                     send_request(brickd_event_sock,enum_stackid,enum_req_funcid)
                  end
               return trigger_enum
            end            
            brickd_call_sock:settimeout(arg or 0.3)
            send_request(brickd_call_sock,enum_stackid,enum_req_funcid)
            devs = {}
            while true do
               local stackid,funcid,resp = recv_response(brickd_call_sock)
               if not stackid then
                  break
               end
               assert(stackid==enum_stackid,funcid==enum_resp_funcid,#resp==enum_resp_length)
               local _,uuid,name,stackid,is_new = resp:unpack(enum_format)
               devs[stackid] = {
                  name = name,
                  uuid = uuid,
                  is_new = is_new
               }
            end            
            return devs
         end

      local get_stack_id = 
         function(uuid)
            assert(#uuid==8)
            if not brickd_event_sock then
               brickd_event_sock = socket.connect(ip,port)
            end
            local ins = 'A'
            local outs = 'A8bbbA40b'
            send_request(brickd_event_sock,0x00,0xff,ins:pack(uuid))
            -- Ignore response! the response carries no relevant information
            -- for this function anyway.
            -- Response will be skipped by next dispatch_events call.
         end
      
      local add_methods = 
         function(dev,methods)
            for name,method in pairs(methods) do
               dev[name] = 
                  function(self,...)
                     return call(self.stackid,method,...)
                  end
            end
         end

      local event_devs = {}

      local add_callbacks = 
         function(dev,callbacks)
            dev.callbacks = {}
            for name,callback in pairs(callbacks) do
               dev[name] = 
                  function(self,f)
                     if not event_devs[self.stackid] then
                        self:enable_events()
                     end
                     self.callbacks[callback.funcid] = callback
                     self.callbacks[callback.funcid].f = f
                  end
            end
         end

      local dispatch_events = 
         function()
            local stackid,funcid,data = recv_response(brickd_event_sock)
            if stackid==enum_stackid and funcid==enum_resp_funcid then
               assert(#data==enum_resp_length)
               if enumerate_callback then
                  local _,uuid,name,stackid,is_new = data:unpack(enum_format)
                  enumerate_callback({uuid=uuid,name=name,stackid=stackid,is_new=is_new})
               end
               return
            end
            local dev = event_devs[stackid] 
            if dev then
               local callback = dev.callbacks[funcid]
               if callback then
                  if callback.ins then
                     if callback.format_ins then
                        callback.f(callback.format_ins(select(2,data:unpack(callback.ins))))
                     else
                        callback.f(select(2,data:unpack(callback.ins)))
                     end
                  else
                     callback.f()
                  end
               end
            end
         end
      
      local device_ctor = 
         function(name)
            local ctor = 
               function(_,stackid)
                  if not devs[stackid] then
                     devs = enumerate()
                  end
                  if not devs[stackid] then
                     error('invalid stackid '..stackid)
                  end
                  local dev = {
                     stackid = stackid,
                     uuid = devs[stackid].uuid,
                     type = name,
                     enable_events = 
                        function(self)
                           event_devs[self.stackid] = self
                           get_stack_id(self.uuid)
                        end
                  }
                  add_methods(dev,require('tinker.'..name).methods)
                  add_callbacks(dev,require('tinker.'..name).callbacks)
                  return dev
               end
            return ctor
         end
      
      local loop = 
         function()
            while true do
               dispatch_events()
            end
         end
      
      local event_socket = 
         function()
            return brickd_event_sock
         end

      return {
         loop = loop,
         event_socket = event_socket,
         dispatch_events = dispatch_events,
         enumerate = enumerate,
         imu = device_ctor('imu'),
         master = device_ctor('master'),
         dc = device_ctor('dc'),
         stepper = device_ctor('stepper'),
         ambient_light = device_ctor('ambient_light'),
         analog_in = device_ctor('analog_in'),
         analog_out = device_ctor('analog_out'),
         current_12 = device_ctor('current_12'),
         current_25 = device_ctor('current_25'),
         distance_ir = device_ctor('distance_ir'),
         dual_relay = device_ctor('dual_relay'),
         humidity = device_ctor('humidity'),
         io_16 = device_ctor('io_16'),
         io_4 = device_ctor('io_4'),
         joystick = device_ctor('joystick'),
         lcd_20x4 = device_ctor('lcd_20x4'),
         lcd_16x2 = device_ctor('lcd_16x2'),
         linear_poti = device_ctor('linear_poti'),
         piezo_buzzer = device_ctor('piezo_buzzer'),
         rotary_poti = device_ctor('rotary_poti'),
         servo = device_ctor('servo'),
         temperature = device_ctor('temperature'),
         temperature_ir = device_ctor('temperature_ir'),
         voltage = device_ctor('voltage')
      }
   end

-- 'old' module export
_G.tinker = {
   ipcon = ipcon
}

-- recommended module export
return {
   ipcon = ipcon
} 


