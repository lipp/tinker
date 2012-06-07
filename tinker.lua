local socket = require'socket'
local pack = require'pack'
local pairs = pairs
local ipairs = ipairs
local assert = assert
local print = print

module('tinker')

local brickd_call_sock
local brickd_event_sock

init = 
   function(ip,port)
      ip = ip or 'localhost'
      port = port or 4223
      brickd_call_sock = socket.connect(ip,port)
      brickd_event_sock = socket.connect(ip,port)
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
   function(sock,stackid,funcid)
      local resp = sock:receive(4)
      if resp then
         local _,rstackid,rfuncid,rlen = resp:unpack(packet_header)
         assert(rstackid == stackid and rfuncid == funcid)
         return sock:receive(rlen-4)
      end
   end

local call = 
   function(stackid,method,...)
      local arguments
      if method.ins then
         arguments = method.ins:pack(...)
      end
      send_request(brickd_call_sock,stackid,method.funcid,arguments)
      if method.outs then
         local resp = recv_response(brickd_call_sock,stackid,funcid)
         return select(2,resp:unpack(method.outs))
      end
   end

enumerate = 
   function(timeout)
      brickd_call_sock:settimeout(timeout or 0.3)
      send_request(brickd_call_sock,0,0xfe)
      local enum_format = 'A8A40bb'
      local devs = {}
      while true do
         local resp = recv_response(brickd_call_sock,0,0xfd)
         if not resp then
            break
         end
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

local method_meta = {
   __index = 
      function(self,name)
         local methods = rawget(self,'methods')
         assert(methods)
         local stackid = rawget(self,'stackid')
         assert(stackid)
         local method = methods[name]
         print(name,method)
         return function(...)
                   return call(stackid,method,...)
                end
      end
}

local add_methods = 
   function(dev,methods)
      for name,method in pairs(methods) do
         dev[name] = 
            function(self,...)
               return call(self.stackid,method,...)
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
   },
}

local device_ctor = 
   function(name)
      return function(stackid)
                local dev = {
                   stackid = stackid,
                }
                add_methods(dev,methods.lcd20x4)
                return dev
             end
   end

lcd20x4 = device_ctor('lcd20x4')

return {
   init = init,
   enumerate = enumerate,
   lcd20x4 = lcd20x4
} 


