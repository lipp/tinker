
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
      set_config = {
         funcid = 6,
         ins = 'bb',
         format_ins = 
            function(cursor,blinking)
               return cursor and 1 or 0,blinking and 1 or 0
            end
      },
      get_config = {
         funcid = 7,
         outs = 'bb',
         format_outs = 
            function(cursor,blinking)
               return cursor > 0, blinking > 0
            end
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
      button_pressed = {
         funcid = 9,
         ins = 'b'
      },
      button_released = {
         funcid = 10,
         ins = 'b'
      }
   }
}
