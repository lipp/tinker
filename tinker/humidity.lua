return {
   methods = {
      get_humidity = {
         funcid = 1,
         outs = 'H'
      },
      get_analog_value = {
         funcid = 2,
         outs = 'H'
      },
      set_humidity_callback_period = {
         funcid = 3,
         ins = 'I'
      },
      get_humidity_callback_period = {
         funcid = 4,
         outs = 'I'
      },
      set_analog_value_callback_period = {
         funcid = 5,
         ins = 'I'
      },
      get_analog_value_callback_period = {
         funcid = 6,
         outs = 'I'
      },
      set_humidity_callback_threshold = {
         funcid = 7,
         ins = 'Ahh',
         format_ins = 
            function(option,min,max)
               if #option ~= 1 then
                  error('invalid option value')
               end
               return option,min,max
            end
      },
      get_humidity_callback_threshold = {
         funcid = 8,
         outs = 'A1hh'
      },
      set_analog_value_callback_threshold = {
         funcid = 9,
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
         funcid = 10,
         outs = 'A1HH'
      },
      set_debounce_period = {
         funcid = 11,
         ins = 'I'
      },
      get_debounce_period = {
         funcid = 12,
         outs = 'I'
      }      
   },
   callbacks = {
      humidity = {
         funcid = 13,
         ins = 'H'
      },
      analog_value = {
         funcid = 14,
         ins = 'H'
      },
      humidity_reached = {
         funcid = 15,
         ins = 'H'
      },
      analog_value_reached = {
         funcid = 16,
         ins = 'H'
      }
   }
}
