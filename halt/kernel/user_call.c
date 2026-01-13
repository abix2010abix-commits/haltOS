#include "header/vga.h"
#include "header/keybord.h" 
#include "header/string.h"

void help();
void uc_editor();
void uc_run();
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
		}else if (strncmp(3, command, "editor") == 0) {
			uc_editor();
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
	printf(" 4- /clr/0x02eidtor/clr/0x0F : open mini editor \n");
	printf(" ---------------------------------------------\n");
}

char code[100][256];
int counter = 0;

void uc_editor() {
    clear_screen();
    counter = 0; 
    char line[256];
    int run = 1;

    while (run) {
        scanf(line);
        if (strncmp(4, line, "exit") == 0) {
            clear_screen();
            printf("uc - script exit [0] \n");
            run = 0;
        } else if (strncmp(3, line, "run") == 0) {
            clear_screen();
            uc_run();
            run = 0;
        } else {
            strcpy(code[counter], line);
            counter++;
        }
    }
}

void uc_run() {
    int i = 0;
    char line[256];
    while (i < counter) {
        strcpy(line, code[i]);


        if (strncmp(4, line, "echo") == 0) {
            int j = 5; 
            while (line[j] != '\0') {
            	if (line[j] == '"') {
            		j++;
            		while (j < 251 && line[j] != '"') {
            			put_char(line[j]);
            			j++;
            		}
            	}
            	j++;
            }
            put_char('\n');
        } else {
            if (line[0] != '\0') {
                printf("syntax error in : \n    > ");
                printf(line);
                printf("\n");
            }
        }
        i++;
    }
}