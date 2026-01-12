#include "header/vga.h"
#include "header/keybord.h" 
#include "header/string.h"

void help();
void uc_script();

void uc_programme() {
	char command[256];

	int run = 1;
	while (run) {
		printf("uc-/clr/0x02$ /clr/0x0F");
		scanf(command);
		if (strncmp(4, command, "help") == 0) {
			help();
		} else if (strncmp(5, command, "clear") == 0) {
			clear_screen();
		} else if (strncmp(4, command, "echo") == 0) {
			for (int i = 5; command[i] != '\0'; i++) {
       			put_char(command[i]);
  	    	}
			printf("\n");
		}else if (strncmp(3, command, "ral") == 0) {
			uc_script();
		}
		else {
			printf("/clr/0x04 Unknown command : /clr/0x0F ");
			printf(command);
			printf("\n write <help> : show command system \n ");
			put_char('\n');
		}
	}
}

void help() {
	printf("welcome to halt os you can use this command : \n");
	printf(" ---------------------------------------------\n");
	printf(" 1- /clr/0x02help/clr/0x0F  : show command in uc terminal\n");
	printf(" 2- /clr/0x02clear/clr/0x0F : remove screen \n");
	printf(" 3- /clr/0x02echo <text>/clr/0x0F : you can print text in screen\n");
	printf(" ---------------------------------------------\n");
}


void uc_script() {
	char line[256];
	clear_screen();
	int run = 1;
	while (run) {
		scanf(line);
		if (strncmp(6, line, "print") == 0) {
			for (int i = 5; line[i] != '\0'; i++) {
       			put_char(line[i]);
  	    	}
			printf("\n");
		} else if (strncmp(4, line, "exit") == 0) {
			clear_screen();
			printf("uc - script exit [0] \n");
			run = 0;
		}else {
		}
    }
}