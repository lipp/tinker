return {
   methods = {
      set_max_velocity = {
         funcid = 1,
         ins = 'H'
      },
      get_max_velocity = {
         funcid = 2,
         outs = 'H'
      },
      get_current_velocity = {
         funcid = 3,
         outs = 'H'
      },
      set_speed_ramping = {
         funcid = 4,
         ins = 'HH'
      },
      get_speed_ramping = {
         funcid = 5,
         outs = 'HH'
      },
      full_brake = {
         funcid = 6
      },
      set_steps = {
         funcid = 11,
         ins = 'i'
      },
      get_steps = {
         funcid = 12,
         outs = 'i'
      },
      get_remaining_steps = {
         funcid = 13,
         ins = 'i'
      },
      drive_forward = {
         funcid = 16
      },
      drive_backward = {
         funcid = 17
      },
      stop = {
         funcid = 18
      },
      set_motor_current = {
         funcid = 22,
         ins = 'H'
      },
      get_motor_current = {
         funcid = 23,
         outs = 'H'
      },
      enable = {
         funcid = 24
      },
      disable = {
         funcid = 25
      },
      is_enabled = {
         funcid = 26,
         outs = 'b',
         format_outs = 
            function(enabled)
               return enabled > 0
            end
      },
      set_current_position = {
         funcid = 7,
         ins = 'i'
      },
      get_current_position = {
         funcid = 8,
         outs = 'i'
      },
      set_target_position = {
         funcid = 9,
         ins = 'i'
      },
      get_target_position = {
         funcid = 10,
         outs = 'i'
      },
      set_step_mode = {
         funcid = 14,
         ins = 'b'
      },
      get_step_mode = {
         funcid = 15,
         outs = 'b'
      },
      get_stack_input_voltage = {
         funcid = 19,
         outs = 'H'
      },
      get_stack_external_input_voltage = {
         funcid = 20,
         outs = 'H'
      },
      get_current_consumption = {
         funcid = 21,
         outs = 'H'
      },
      set_decay = {
         funcid = 27,
         ins = 'H'
      },
      get_decay = {
         funcid = 28,
         outs = 'H'
      },
      set_sync_ret = {
         funcid = 33,
         ins = 'b',
         format_ins = 
            function(sync)
               return sync and 1 or 0
            end
      },
      is_sync_ret = {
         funcid = 34,
         outs = 'b',
         format_outs = 
            function(sync)
               return sync > 0
            end
      },
      set_minimum_voltage = {
         funcid = 29,
         ins = 'H'
      },
      get_minimum_voltage = {
         funcid = 30,
         outs = 'H'
      }
   },
   callbacks = {
      under_voltage = {
         funcid = 31,
         ins = 'H'
      },
      position_reached = {
         funcid = 32,
         ins = 'i'
      }
   }
}
