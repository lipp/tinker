return {
   methods = {
      get_orientation = {
         funcid = 5,
         outs = 'hhh'
      },
      set_orientation_period = {
         funcid = 27,
         ins = 'I'
      }
   },
   callbacks = {
      orientation = {
         funcid = 35,
         ins = 'hhh'
      },
      quaternion = {
         funcid = 36,
         ins = 'ffff'
      }
   }
}
