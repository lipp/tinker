-- load tinker module
local tinker = require'tinker'
-- load socket module for sleeping
local socket = require'socket'

-- create ipcon to brickd
local ipcon = tinker.ipcon()
-- create (and add) lcd20x4 instance, change uid approp.
local lcd = ipcon:lcd20x4('8vE')

-- do some funny lcd control
lcd:backlight_on()
lcd:write_line(0,0,'hello')
socket.sleep(2)
lcd:write_line(1,1,'good bye')
socket.sleep(2)
lcd:backlight_off()
