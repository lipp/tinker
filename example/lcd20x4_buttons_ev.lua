local tinker = require'tinker'
local ev = require'ev'

local ipcon = tinker.ipcon()
local lcd = ipcon:lcd_20x4(2)
lcd:backlight_on()
lcd:button_pressed( 
   function(index)
      lcd:clear_display()
      lcd:write_line(index,0,'button '..index..' pressed')
   end)
lcd:button_released( 
   function(index)
      lcd:clear_display()
      lcd:write_line(index,0,'button '..index..' released')
   end)
lcd:enable_events()

local sock = ipcon:event_socket()

local io = ev.IO.new(
   function()
      ipcon:dispatch_events()
   end,sock:getfd(),ev.READ)

io:start(ev.Loop.default)
ev.Loop.default:loop()
