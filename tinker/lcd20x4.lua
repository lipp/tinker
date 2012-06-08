
return {
   methods = {
      backlight_on = {
         funcid = 3
      },
      backlight_off = {
         funcid = 4
      },
      write_line = {
         funcid = 1,
         ins = 'bbA',
         format_ins = 
            function(pos,line,text)
               if pos+#text > 20 then
                  error('text does not fit on display')
               end
               text = text..string.rep(string.char(0),20-#text)
               return pos,line,text
            end
      },
      clear_display = {
         funcid = 2
      },
      is_backlight_on = {
         funcid = 5,
         outs = 'b',
         format_outs =
            function(is_on)
               return is_on > 0 
            end
      }
   },
   callbacks = {
      [9] = {
         name = 'button_pressed',
         ins = 'b'
      },
      [10] = {
         name = 'button_released',
         ins = 'b'
      }
   }
}
