#!/usr/bin/env lua
local tinker = require'tinker'
local ev = require'ev'
local loop = ev.Loop.default
local jet = require'jet.peer'.new{loop=loop}
local ipcon = tinker.ipcon()

local imu = ipcon:imu(arg[1] or 5)

-- orientation
local orientation_state = jet:state
{
   path = 'imu/orientation'
}
imu:orientation(
   function(roll,pitch,yaw)
      orientation_state:value
      {
         roll = roll,
         pitch = pitch,
         yaw = yaw
      }
   end)

-- orientation period
local default_orientation_period = 300
jet:state
{
   path = 'imu/orientation_period',
   set = function(val)
      imu:set_orientation_period(val)
   end,
   value = default_orientation_period
}
imu:set_orientation_period(300)



-- angular_velocity
local angular_velocity_state = jet:state
{
   path = 'imu/angular_velocity'
}
imu:angular_velocity(
   function(x,y,z)
      angular_velocity_state:value
      {
         x = x,
         y = y,
         z = z
      }
   end)

-- angular_velocity period
local default_angular_velocity_period = 300
jet:state
{
   path = 'imu/angular_velocity_period',
   set = function(val)
      imu:set_angular_velocity_period(val)
   end,
   value = default_angular_velocity_period
}
imu:set_angular_velocity_period(300)


-- acceleration
local acceleration_state = jet:state
{
   path = 'imu/acceleration'
}
imu:acceleration(
   function(x,y,z)
      acceleration_state:value
      {
         x = x,
         y = y,
         z = z
      }
   end)

-- acceleration period
local default_acceleration_period = 300
jet:state
{
   path = 'imu/acceleration_period',
   set = function(val)
      imu:set_acceleration_period(val)
   end,
   value = default_acceleration_period
}
imu:set_acceleration_period(300)


-- io/event stuff
local sock = ipcon:event_socket()

local io = ev.IO.new(
   function()
      ipcon:dispatch_events()
   end,sock:getfd(),ev.READ)

io:start(loop)
loop:loop()
