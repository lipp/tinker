local tinker = require'tinker'

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
ipcon:loop()
lcd:backlight_off()
