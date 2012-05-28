local tinker = require'tinker'
local socket = require'socket'

local ipcon = tinker.ipcon()
local lcd = ipcon:lcd20x4('8eV')

lcd:backlight_on()
lcd:write_line(0,0,'hello')
socket.sleep(2)
lcd:write_line(1,1,'good bye')
socket.sleep(2)
lcd:backlight_off()
