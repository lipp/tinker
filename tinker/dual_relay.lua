return {
   methods = {
      set_state = {
         funcid = 1,
         ins = 'bb',
         format_ins = 
            function(s1,s2)
               return s1 > 0, s2 > 0
            end
      },
      get_state = {
         funcid = 2,
         outs = 'bb',
         format_outs = 
            function(s1,s2)
               return s1 and 1 or 0, s2 and 1 or 0
            end
      }
   },
   callbacks = {
   }
}
