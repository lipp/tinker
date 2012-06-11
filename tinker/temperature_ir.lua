return {
   methods = {
      get_ambient_temperature = {
         funcid = 1,
         outs = 'h'
      },
      get_object_temperature = {
         funcid = 2,
         outs = 'h'
      },
      set_emissivity = {
         funcid = 3,
         ins = 'H'
      },
      get_emissivity = {
         funcid = 4,
         outs = 'H'
      },
      set_ambient_temperature_callback_period = {
         funcid = 5,
         ins = 'I'
      },
      get_ambient_temperature_callback_period = {
         funcid = 6,
         outs = 'I'
      },
      set_object_temperature_callback_period = {
         funcid = 7,
         ins = 'I'
      },
      get_object_temperature_callback_period = {
         funcid = 8,
         outs = 'I'
      },
      set_ambient_temperature_callback_threshold = {
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
      get_ambient_temperature_callback_threshold = {
         funcid = 10,
         outs = 'A1hh'
      },
      set_object_temperature_callback_threshold = {
         funcid = 11,
         ins = 'Ahh',
         format_ins = 
            function(option,min,max)
               if #option ~= 1 then
                  error('invalid option value')
               end
               return option,min,max
            end
      },
      get_object_temperature_callback_threshold = {
         funcid = 12,
         outs = 'A1hh'
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
      ambient_temperature = {
         funcid = 15,
         ins = 'h'
      },
      object_temperature = {
         funcid = 16,
         ins = 'h'
      },
      ambient_temperature_reached = {
         funcid = 17,
         ins = 'h'
      },
      object_temperature_reached = {
         funcid = 18,
         ins = 'h'
      }
   }
}
