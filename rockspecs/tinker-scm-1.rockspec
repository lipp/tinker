package = "tinker"
version = "scm-1"
source = {
   url = "git://github.com/lipp/tinker.git",
}
description = {
   summary = "Lua bindings to tinkerforge bricks and bricklets.",
   homepage = "http://github.com/lipp/tinker",
   license = "MIT/X11",
}
dependencies = {
   "lua >= 5.1",
   "luasocket",
   "lpack"
}
build = {
   type = "none",
   install = {
      lua = {
         ['tinker'] = 'tinker.lua',
         ['tinker.imu'] = 'tinker/imu.lua',
         ['tinker.master'] = 'tinker/master.lua',
         ['tinker.dc'] = 'tinker/dc.lua',
         ['tinker.stepper'] = 'tinker/stepper.lua',
         ['tinker.ambient_light'] = 'tinker/ambient_light.lua',
         ['tinker.analog_in'] = 'tinker/analog_in.lua',
         ['tinker.analog_out'] = 'tinker/analog_out.lua',
         ['tinker.current_25'] = 'tinker/current_25.lua',
         ['tinker.current_12'] = 'tinker/current_12.lua',
         ['tinker.distance_ir'] = 'tinker/distance_ir.lua',
         ['tinker.dual_relay'] = 'tinker/dual_relay.lua',
         ['tinker.humidity'] = 'tinker/humidity.lua',
         ['tinker.io_16'] = 'tinker/io_16.lua',
         ['tinker.io_4'] = 'tinker/io_4.lua',
         ['tinker.joystick'] = 'tinker/joystick.lua',
         ['tinker.lcd_20x4'] = 'tinker/lcd_20x4.lua',
         ['tinker.lcd_16x2'] = 'tinker/lcd_16x2.lua',
         ['tinker.linear_poti'] = 'tinker/linear_poti.lua',
         ['tinker.piezo_buzzer'] = 'tinker/piezo_buzzer.lua',
         ['tinker.rotart_poti'] = 'tinker/rotary_poti.lua',
         ['tinker.temperature'] = 'tinker/temperature.lua',
         ['tinker.temperature_ir'] = 'tinker/temperature_ir.lua',
         ['tinker.voltage'] = 'tinker/voltage.lua'
      }
   }
}

