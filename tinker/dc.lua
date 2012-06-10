return {
   methods = {
      set_velocity = {
         funcid = 1,
         ins = 'h'
      },
      get_velocity = {
         funcid = 2,
         outs = 'h'
      },
      get_current_velocity = {
         funcid = 3,
         outs = 'h'
      },
      set_acceleration = {
         funcid = 4,
         ins = 'h'
      },
      get_acceleration = {
         funcid = 5,
         outs = 'h'
      },
      full_brake = {
         funcid = 8,
      },
      enable = {
         funcid = 12
      },
      disable = {
         funcid = 13
      },
      is_enabled = {
         funcid = 14,
         outs = 'b',
         format_outs = 
            function(enabled)
               return enabled > 0
            end
      },
      set_pwm_frequency = {
         funcid = 6,
         ins = 'H'
      },
      get_pwm_frequency = {
         funcid = 7,
         outs = 'H'
      },
      get_stack_input_voltage = {
         funcid = 9,
         outs = 'H'
      },
      get_external_input_voltage = {
         funcid = 10,
         outs = 'H'
      },
      get_current_consumption = {
         funcid = 11,
         outs = 'H'
      },
      set_drive_mode = {
         funcid = 17,
         ins = 'b'
      },
      get_drive_mode = {
         funcid = 18,
         outs = 'b'
      },
      set_minimum_voltage = {
         funcid = 15,
         ins = 'H'
      },
      get_minimum_voltage = {
         funcid = 16,
         outs = 'H'
      },
      set_current_velocity_period = {
         funcid = 19,
         ins = 'H'
      },
      get_current_velocity_period = {
         funcid = 20,
         outs = 'H'
      }
   },
   callbacks = {
      velocity_reached = {
         funcid = 23,
         ins = 'h'
      },
      current_velocity = {
         funcid = 24,
         ins = 'h'
      }
   }
}
