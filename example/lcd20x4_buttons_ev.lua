local tinker = require'tinker'
local ev = require'ev'

tinker.init()
local lcd = tinker.lcd20x4(2)
lcd:backlight_on()
lcd.button_pressed = 
   function(index)
      lcd:clear_display()
      lcd:write_line(0,0,'button '..index..' pressed')
   end
lcd:enable_events()

local sock = tinker.event_socket()
--sock:settimeout(0)
local io = ev.IO.new(
   function()
      tinker.dispatch_events()
   end,sock:getfd(),ev.READ)

io:start(ev.Loop.default)
ev.Loop.default:loop()
