return {
   methods = {
      get_stack_voltage = {
         funcid = 1,
         outs = 'H'
      },
      get_stack_current = {
         funcid = 2,
         outs = 'H'
      },
      set_extension_type = {
         funcid = 3,
         ins = 'bI'
      },
      get_extension_type = {
         funcid = 4,
         ins = 'b',
         outs = 'H'
      },
      is_chibi_present = {
         funcid = 5,
         outs = 'b',
         format_outs = 
            function(present)
               return present > 0
            end
      },
      set_chibi_address = {
         funcid = 6,
         ins = 'b'
      },
      get_chibi_address = {
         funcid = 7,
         outs = 'b'
      },
      set_chibi_master_address = {
         funcid = 8,
         ins = 'b'
      },
      get_chibi_master_address = {
         funcid = 9,
         outs = 'b'
      },
      set_chibi_slave_address = {
         funcid = 10,
         ins = 'bb'
      },
      get_chibi_slave_address = {
         funcid = 11,
         ins = 'b',
         outs = 'b'
      },
      get_chibi_signal_strength = {
         funcid = 12,
         outs = 'b'
      },
      get_chibi_error_log = {
         funcid = 13,
         outs = 'HHHH'
      },
      set_chibi_frequency = {
         funcid = 14,
         ins = 'b'
      },
      get_chibi_frequency = {
         funcid = 15,
         outs = 'b'
      },
      set_chibi_channel = {
         funcid = 16,
         ins = 'b'
      },
      get_chibi_channel = {
         funcid = 17,
         outs = 'b'
      }
   },
   callbacks = {
   }
}
