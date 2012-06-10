return {
   methods = {
      get_current = {
         funcid = 1,
         outs = 'h'
      },
      calibrate = {
         funcid = 2
      },
      is_over_current = {
         funcid = 3,
         outs = 'b',
         format_outs = 
            function(over)
               return over > 0
            end
      },
      get_analog_value = {
         funcid = 4,
         outs = 'H'
      },
      set_current_callback_period = {
         funcid = 5,
         ins = 'I'
      },
      get_current_callback_period = {
         funcid = 6,
         outs = 'I'
      },
      set_analog_value_callback_period = {
         funcid = 7,
         ins = 'I'
      },
      get_analog_value_callback_period = {
         funcid = 8,
         outs = 'I'
      },
      set_current_callback_threshold = {
         funcid = 9,
         ins = 'Ahh',
         format_ins = 
            function(option,min,max)
               if #option ~= 1 then
                  error('invalid option value')
               end
               return option,min,max
            end
      },
      get_current_callback_threshold = {
         funcid = 10,
         outs = 'A1hh'
      },
      set_analog_value_callback_threshold = {
         funcid = 11,
         ins = 'AHH',
         format_ins = 
            function(option,min,max)
               if #option ~= 1 then
                  error('invalid option value')
               end
               return option,min,max
            end
      },
      get_analog_value_callback_threshold = {
         funcid = 12,
         outs = 'A1HH'
      },
      set_debounce_period = {
         funcid = 13,
         ins = 'I'
      },
      get_debounce_period = {
         funcid = 14,
         outs = 'I'
      }      
   },
   callbacks = {
      current = {
         funcid = 15,
         ins = 'h'
      },
      analog_value = {
         funcid = 16,
         ins = 'H'
      },
      current_reached = {
         funcid = 17,
         ins = 'h'
      },
      analog_value_reached = {
         funcid = 18,
         ins = 'H'
      },
      over_current = {
         funcid = 19
      }
   }
}
