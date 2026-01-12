#include "header/vga.h"
#include "header/keybord.h" 
#include "header/string.h"
#include "header/uc.h"

void kmain(void) {
   clear_screen();
   char command[256];
   printf("\n Halt os 0.1 virsion\n \n");
   printf("#   #      #     #    ####### \n");
 	printf("#   #    #  #    #       #        Halt Kernel \n");
   printf("#####   #    #   #       #        color bar :\n");
   printf("#   #  ########  #       #\n");
   printf("#   #  #      #  #####   #        ");
   printf("/clr/0x10 /clr/0x20 /clr/0x30 /clr/0x40 /clr/0x50 /clr/0x60 /clr/0x70 /clr/0x80 /clr/0x90 /clr/0xA0 /clr/0xB0 /clr/0xC0 /clr/0xD0 /clr/0xE0 /clr/0xf0 /clr/0x0F\n\n");
   uc_programme();
}
