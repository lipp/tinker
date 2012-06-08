return {
   methods = {
      get_orientation = {
         funcid = 5,
         outs = 'hhh'
      },
      get_quaternion = {
         funcid = 6,
         outs = 'ffff'
      },
      leds_on = {
         funcid = 8
      },
      leds_off = {
         funcid = 9
      },
      are_leds_on = {
         funcid = 10,
         outs = 'b',
         format_outs = 
            function(on)
               return on > 0
            end
      },
      set_convergence_speed = {
         funcid = 15,
         ins = 'H'
      },
      get_convergence_speed = {
         funcid = 16,
         outs = 'H'
      },
      get_acceleration = {
         funcid = 1,
         outs = 'hhh'
      },
      get_magnetic_field = {
         funcid = 2,
         outs = 'hhh'
      },
      get_angular_velocity = {
         funcid = 3,
         outs = 'hhh'
      },
      get_all_data = {
         funcid = 4,
         outs = 'hhhhhhhhhh'
      },
      get_imu_temperature = {
         funcid = 7,
         outs = 'h'
      },
      set_acceleration_range = {
         funcid = 11,
         ins = 'b'
      },
      get_acceleration_range = {
         funcid = 12,
         outs = 'b'
      },
      set_magnetometer_range = {
         funcid = 13,
         ins = 'b'
      },
      get_magnetometer_range = {
         funcid = 14,
         outs = 'b'
      },
      set_calibration = {
         funcid = 17,
         ins = 'bh10' -- strange, maybe symmetric to get_calibration?
      },
      get_calibration = {
         funcid = 18,
         ins = 'b',
         outs = 'h10'
      },
      set_acceleration_period = {
         funcid = 19,
         ins = 'I'
      },
      get_acceleration_period = {
         funcid = 20,
         outs = 'I'
      },
      set_magnetic_field_period = {
         funcid = 21,
         ins = 'I'
      },
      get_magnetic_field_period = {
         funcid = 22,
         outs = 'I'
      },
      set_angular_velocity_period = {
         funcid = 23,
         ins = 'I'
      },
      get_angular_velocity_period = {
         funcid = 24,
         outs = 'I'
      },
      set_all_data_period = {
         funcid = 25,
         ins = 'I'
      },
      get_all_data_period = {
         funcid = 26,
         outs = 'I'
      },
      set_orientation_period = {
         funcid = 27,
         ins = 'I'
      },
      get_orientation_period = {
         funcid = 28,
         outs = 'I'
      },
      set_quaternion_period = {
         funcid = 29,
         ins = 'I'
      },
      get_quaternion_period = {
         funcid = 30,
         outs = 'I'
      }
   },
   callbacks = {
      acceleration = {
         funcid = 31,
         ins = 'hhh'
      },
      magnetic_field = {
         funcid = 32,
         ins = 'hhh'
      },
      angular_velocity = {
         funcid = 33,
         ins = 'hhh'
      },
      all_data = {
         funcid = 34,
         ins = 'hhhhhhhhhh'
      },
      orientation = {
         funcid = 35,
         ins = 'hhh'
      },
      quaternion = {
         funcid = 36,
         ins = 'ffff'
      }
   }
}
