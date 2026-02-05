#include "header/vga.h"
#include "header/keybord.h" 
#include "header/string.h"
#include "header/uc.h"
#include "header/io_port.h"
#include "header/time.h"

void kmain(void) {
   while (1) {
      clear_screen();
      console();
   }

}
// 100