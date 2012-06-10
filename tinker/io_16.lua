return {
   methods = {
      set_port = {
         funcid = 1,
         ins = 'cb'
      },
      get_port = {
         funcid = 2,
         ins = 'c',
         outs = 'b'
      },
      set_port_configuration = {
         funcid = 3,
         ins = 'cbcb'
         format_ins = 
            function(port,mask,direction,value)
               return port,mask,direction,(value and 1 or 0)
            end
      },
      get_port_configuration = {
         funcid = 4,
         ins = 'c',
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
      set_port_interrupt = {
         funcid = 7,
         ins = 'cb'
      },
      get_port_interrupt = {
         funcid = 8,
         ins = 'c',
         outs = 'b'
      }
   },
   callbacks = {
      interrupt = {
         funcid = 9,
         ins = 'cbb'
      }
   }
}
