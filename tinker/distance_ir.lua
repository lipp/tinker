return {
   methods = {
      get_distance = {
         funcid = 1,
         outs = 'H'
      },
      get_analog_value = {
         funcid = 2,
         outs = 'H'
      },
      set_sampling_point = {
         funcid = 3,
         ins = 'bH'
      },
      get_sampling_point = {
         funcid = 4,
         ins = 'b',
         outs = 'H'
      },
      set_distance_callback_period = {
         funcid = 5,
         ins = 'I'
      },
      get_distance_callback_period = {
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
      set_distance_callback_threshold = {
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
      get_distance_callback_threshold = {
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
      distance = {
         funcid = 15,
         ins = 'H'
      },
      analog_value = {
         funcid = 16,
         ins = 'H'
      },
      distance_reached = {
         funcid = 17,
         ins = 'H'
      },
      analog_value_reached = {
         funcid = 18,
         ins = 'H'
      }
   }
}
