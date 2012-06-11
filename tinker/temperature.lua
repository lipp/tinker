return {
   methods = {
      get_temperature = {
         funcid = 1,
         outs = 'h'
      },
      set_temperature_callback_period = {
         funcid = 2,
         ins = 'I'
      },
      get_temperature_callback_period = {
         funcid = 3,
         outs = 'I'
      },
      set_temperature_callback_threshold = {
         funcid = 4,
         ins = 'Ahh',
         format_ins = 
            function(option,min,max)
               if #option ~= 1 then
                  error('invalid option value')
               end
               return option,min,max
            end
      },
      get_temperature_callback_threshold = {
         funcid = 5,
         outs = 'A1hh'
      },
      set_debounce_period = {
         funcid = 6,
         ins = 'I'
      },
      get_debounce_period = {
         funcid = 7,
         outs = 'I'
      }      
   },
   callbacks = {
      temperature = {
         funcid = 8,
         ins = 'h'
      },
      temperature_reached = {
         funcid = 9,
         ins = 'h'
      }
   }
}
