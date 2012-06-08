local tinker = require'tinker'

tinker.init()
local devs = tinker.enumerate()

for stackid,dev in pairs(devs) do
   print('stackid: '..stackid, 'name :'..dev.name)
end
