return {
   methods = {
      beep = {
         funcid = 1,
         ins = 'I'
      },
      morse_code = {
         funcid = 2,
         ins = 'A',
         format_ins = 
            function(morse)
               if #morse > 60 then
                  error('morse too long')
               end
               morse = morse..string.rep(string.char(0),60-#text)
               return morse
            end
      }
   },
   callbacks = {
      beep_finished = {
         funcid = 3
      },
      morse_code_finished = {
         funcid = 4
      }
   }
}
