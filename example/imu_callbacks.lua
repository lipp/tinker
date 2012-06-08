local tinker = require'tinker'

local ipcon = tinker.ipcon()
local lcd = ipcon:lcd20x4(2)
lcd:backlight_on()
lcd:clear_display()
local imu = ipcon:imu(5)
imu:set_orientation_period(300)
imu:orientation(
   function(roll,pitch,yaw)
      lcd:clear_display()
      lcd:write_line(0,0,'roll:'..roll)
      lcd:write_line(1,0,'pitch:'..pitch)
      lcd:write_line(2,0,'yaw:'..yaw)
   end)
imu:enable_events()
ipcon:loop()
