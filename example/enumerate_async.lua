local tinker = require'tinker'

local ipcon = tinker.ipcon()
local trigger_enum = ipcon:enumerate(
   function(dev)
      print('stackid: '..dev.stackid, 'name :'..dev.name)
   end)
trigger_enum()
ipcon:loop()

