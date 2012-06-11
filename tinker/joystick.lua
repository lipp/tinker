return {
   methods = {
      get_position = {
         funcid = 1,
         outs = 'hh'
      },
      is_pressed = {
         funcid = 2,
         outs = 'b',
         format_outs = 
            function(pressed)
               return pressed > 0
            end
      },
      get_analog_value = {
         funcid = 3,
         outs = 'HH'
      },
      calibrate = {
         funcid = 4
      },
      set_position_callback_period = {
         funcid = 5,
         ins = 'I'
      },
      get_position_callback_period = {
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
      set_position_callback_threshold = {
         funcid = 9,
         ins = 'Ahhhh',
         format_ins = 
            function(option,...)
               if #option ~= 1 then
                  error('invalid option value')
               end
               return option,...
            end
      },
      get_position_callback_threshold = {
         funcid = 10,
         outs = 'A1hhhh'
      },
      set_analog_value_callback_threshold = {
         funcid = 11,
         ins = 'AHHHH',
         format_ins = 
            function(option,...)
               if #option ~= 1 then
                  error('invalid option value')
               end
               return option,...
            end
      },
      get_analog_value_callback_threshold = {
         funcid = 12,
         outs = 'A1HHHH'
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
      position = {
         funcid = 15,
         ins = 'hh'
      },
      analog_value = {
         funcid = 16,
         ins = 'HH'
      },
      position_reached = {
         funcid = 17,
         ins = 'hh'
      },
      analog_value_reached = {
         funcid = 18,
         ins = 'HH'
      }
   }
}
