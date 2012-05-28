local tinker = require'tinker'

local ipcon = tinker.ipcon()
local lcd = ipcon:lcd20x4('8vE')
lcd:backlight_on()
lcd:button_pressed(
	function(index)
		lcd:clear_display()
	      	lcd:write_line(0,0,'button '..index..' pressed')
	end)
ipcon:join_thread()
lcd:backlight_off()
