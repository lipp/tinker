return {
   methods = {
      enable = {
         funcid = 1,
         ins = 'b'
      },
      disable = {
         funcid = 2,
         ins = 'b'
      },
      is_enabled = {
         funcid = 3,
         outs = 'b',
         format_outs = 
            function(enabled)
               return enabled > 0
            end
      },
      set_position = {
         funcid = 4,
         ins = 'bh'
      },
      get_position = {
         funcid = 5,
         outs = 'bh'
      },
      get_current_position = {
         funcid = 6,
         ins = 'b',
         outs = 'h'
      },
      set_velocity = {
         funcid = 7,
         ins = 'bH'
      },
      get_velocity = {
         funcid = 8,
         ins = 'b',
         outs = 'H'
      },
      get_current_velocity = {
         funcid = 9,
         ins = 'b',
         outs = 'H'
      },
      set_acceleration = {
         funcid = 10,
         ins = 'bH'
      },
      get_acceleration = {
         funcid = 11,
         ins = 'b',
         outs = 'H'
      },
      set_output_voltage = {
         funcid = 12,
         ins = 'H'
      },
      get_output_voltage = {
         funcid = 13,
         outs = 'H'
      },
      set_pulse_width = {
         funcid = 14,
         ins = 'bHH'
      },
      get_pulse_width = {
         funcid = 15,
         ins = 'b',
         outs = 'HH'
      },
      set_degree = {
         funcid = 16,
         ins = 'bHH'
      },
      get_degree = {
         funcid = 17,
         ins = 'b',
         outs = 'HH'
      },
      set_period = {
         funcid = 18,
         ins = 'bH'
      },
      get_period = {
         funcid = 19,
         ins = 'b',
         outs = 'H'
      },
      get_servo_current = {
         funcid = 20,
         ins = 'b',
         outs = 'H'
      },
      get_overall_current = {
         funcid = 21,
         outs = 'H'
      },
      get_stack_input_voltage = {
         funcid = 22,
         outs = 'H'
      },
      get_external_input_voltage = {
         funcid = 23,
         outs = 'H'
      },
      set_minimum_voltage = {
         funcid = 24,
         ins = 'H'
      },
      get_minimum_voltage = {
         funcid = 25,
         outs = 'H'
      }
   },
   callbacks = {
      under_voltage = {
         funcid = 26,
         ins = 'H'
      },
      position_reached = {
         funcid = 27,
         ins = 'bh'
      }
   }
}
