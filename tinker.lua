local socket = require'socket'
local pack = require'pack'
local pairs = pairs
local ipairs = ipairs
local assert = assert
local error = error
local print = print
local string = string
local select = select

module('tinker')

local brickd_call_sock
local brickd_event_sock
local devs

init = 
   function(ip,port)
      ip = ip or 'localhost'
      port = port or 4223
      brickd_call_sock = socket.connect(ip,port)
      brickd_event_sock = socket.connect(ip,port)
      devs = enumerate()
   end

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

enumerate = 
   function(timeout)
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

local enable_events = 
   function(uuid)
      assert(#uuid==8)
      local get_stack_id = {
         funcid = 0xff,
         ins = 'A',
         outs = 'A8bbbA40b'
      }
      local stackid = 0x00
      local ruuid = call(brickd_event_sock,stackid,method,uuid)
      assert(ruuid==uuid)
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

local callbacks = {
   lcd20x4 = {
      [9] = {
         name = 'button_pressed',
         ins = 'b'
      },
      [10] = {
         name = 'button_pressed',
         ins = 'b'
      }
   }
}

local events_devs = {}

local dispatch_events = 
   function()
      local stackid,funcid,data = recv_response(brickd_event_sock)
      local dev = event_devs[stackid] 
      if not dev then
         return
      end
      local callback = callbacks[dev.type][funcid]
      if not callback then
         return
      end
      local dev_func = devs[callback.name]
      if dev_func then
         if callback.format_ins then
            dev_func(callback.format_ins(data:unpack(callback.ins)))
         else
            dev_func(data:unpack(callback.ins))
         end
      end
   end


local methods = {
   lcd20x4 = {
      backlight_on = {
         funcid = 3
      },
      backlight_off = {
         funcid = 4
      },
      write_line = {
         funcid = 1,
         ins = 'bbA',
         format_ins = 
            function(pos,line,text)
               if pos+#text > 20 then
                  error('text does not fit on display')
               end
               text = text..string.rep(string.char(0),20-#text)
               return pos,line,text
            end
      },
      clear_display = {
         funcid = 2
      },
      is_backlight_on = {
         funcid = 5,
         outs = 'b',
         format_outs =
            function(is_on)
               return is_on > 0 
            end
      }
   },
}

local device_ctor = 
   function(name)
      return function(stackid)
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
                         enable_events(self.uuid)
                      end
                }
                add_methods(dev,methods.lcd20x4)
                return dev
             end
   end

loop = 
   function()
      while true do
         dispatch_event()
      end
   end

lcd20x4 = device_ctor('lcd20x4')

return {
   init = init,
   enumerate = enumerate,
   lcd20x4 = lcd20x4
} 


