-- load tinker module
local tinker = require'tinker'
-- load socket module for sleeping
local socket = require'socket'

-- connect to brickd
local ipcon = tinker.ipcon()
-- create (and add) lcd20x4 instance, change uid approp.
local lcd = ipcon:lcd20x4(2)

-- do some funny lcd control
lcd:backlight_on()
assert(lcd:is_backlight_on())
lcd:write_line(0,0,'hello')
socket.sleep(2)
lcd:write_line(1,1,'good bye')
socket.sleep(2)
local cursor = true
local blink = true
lcd:set_config(cursor,blink)
local rcursor,rblink = lcd:get_config()
assert(rcursor==cursor,rblinking==blinking)
lcd:backlight_off()
assert(lcd:is_backlight_on()==false)
