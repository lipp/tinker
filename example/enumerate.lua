local tinker = require'tinker'

local ipcon = tinker.ipcon()
local devs = ipcon:enumerate()

for stackid,dev in pairs(devs) do
   print('stackid: '..stackid, 'name :'..dev.name)
end
