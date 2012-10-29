#!/usr/bin/env lua
local tinker = require'tinker'
local ev = require'ev'
local loop = ev.Loop.default
local jet = require'jet.peer'.new{loop=loop}
local ipcon = tinker.ipcon()
local lcd = ipcon:lcd_20x4(arg[1] or 2)

lcd:backlight_on()
jet:state
{
   path = 'lcd/backlight',
   set = function(val)
      if val == 'on' then
         lcd:backlight_on()
      else
         lcd:backlight_off()
      end
   end,
   value = 'on'
}

local button_state = function(index)
   return jet:state
   {
      path = 'lcd/button_'..index,      
      value = 'released'
   }
end

local bs = {
   button_state(1),
   button_state(2),
   button_state(3),
}

lcd:button_pressed( 
   function(index)
      bs[index+1]:value('pressed')
   end)
lcd:button_released( 
   function(index)
      bs[index+1]:value('released')
   end)

local sock = ipcon:event_socket()

local io = ev.IO.new(
   function()
      ipcon:dispatch_events()
   end,sock:getfd(),ev.READ)

io:start(loop)
loop:loop()
