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

module('tinker')

-- stackid,funcid,length
local packet_header = 'bbH'

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
      local brickd_event_sock = socket.connect(ip,port)
      
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
      
      local enumerate =
         function(_,timeout)
            brickd_call_sock:settimeout(timeout or 0.3)
            send_request(brickd_call_sock,0,0xfe)
            local enum_format = 'A8A40bb'
            local devs = {}
            while true do
               local stackid,funcid,resp = recv_response(brickd_call_sock)
               if not stackid then
                  break
               end
               assert(stackid==0,funcid==0xfd,#resp==50)
               local _,uuid,name,stackid,is_new = resp:unpack(enum_format)
               devs[stackid] = {
                  name = name,
                  uuid = uuid,
                  is_new = is_new
               }
            end
            return devs
         end

      local devs = enumerate()

      local get_stack_id = 
         function(uuid)
            assert(#uuid==8)
            local ins = 'A'
            local outs = 'A8bbbA40b'
            send_request(brickd_event_sock,0x00,0xff,ins:pack(uuid))
            local stackid,funcid,data = recv_response(brickd_event_sock)
            assert(stackid==0x00,funcid==0xff)
            local _,ruuid,f1,f2,f3,name,rstackid = data:unpack(outs)
            --   print(data:unpack(outs))
            --   assert(stackid==rstackid)
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

      local add_callbacks = 
         function(dev,callbacks)
            dev.callbacks = {}
            for name,callback in pairs(callbacks) do
               dev[name] = 
                  function(self,f)
                     self.callbacks[callback.funcid] = callback
                     self.callbacks[callback.funcid].f = f
                  end
            end
         end

      local event_devs = {}

      local dispatch_events = 
         function()
            local stackid,funcid,data = recv_response(brickd_event_sock)
            local dev = event_devs[stackid] 
            if not dev then
         return
            end
            local callback = dev.callbacks[funcid]
            if callback then
               if callback.format_ins then
                  callback.f(callback.format_ins(select(2,data:unpack(callback.ins))))
               else
                  callback.f(select(2,data:unpack(callback.ins)))
               end
            end
         end

      local device_ctor = 
         function(name)
            return function(_,stackid)
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
         lcd20x4 = device_ctor('lcd20x4'),
         imu = device_ctor('imu')
      }
   end

ipcon = ipcon
return {
   ipcon = ipcon
} 


