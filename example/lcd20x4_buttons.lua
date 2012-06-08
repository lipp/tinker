local tinker = require'tinker'

tinker.init()
local lcd = tinker.lcd20x4(2)
lcd:backlight_on()
lcd.button_pressed = 
   function(index)
      lcd:clear_display()
      lcd:write_line(0,0,'button '..index..' pressed')
   end
lcd:enable_events()
tinker.loop()
lcd:backlight_off()
