return {
   methods = {
      set_value = {
         funcid = 1,
         ins = 'b'
      },
      get_port = {
         funcid = 2,
         outs = 'b'
      },
      set_configuration = {
         funcid = 3,
         ins = 'bcb',
         format_ins = 
            function(mask,direction,value)
               return mask,direction,(value and 1 or 0)
            end
      },
      get_configuration = {
         funcid = 4,
         outs = 'bb'
      },
      set_debounce_period = {
         funcid = 5,
         ins = 'I'
      },
      get_debounce_period = {
         funcid = 6,
         outs = 'I'
      },
      set_interrupt = {
         funcid = 7,
         ins = 'b'
      },
      get_interrupt = {
         funcid = 8,
         outs = 'b'
      }
   },
   callbacks = {
      interrupt = {
         funcid = 9,
         ins = 'bb'
      }
   }
}
