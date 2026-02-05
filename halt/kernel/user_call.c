#include "header/vga.h"
#include "header/keybord.h" 
#include "header/string.h"
#include "header/time.h"
#include "header/io_port.h"
#include "header/shell.h"

struct command {
    char *name;
    void (*func)();
};

struct command cmd_table[] = {
    {"help", shell_help},
    {"clear", clear_screen},
    {"editor", uc_editor},
    {"about", shell_about},
    {"time", shell_time},
    {"shutdown", shell_shutdown}
};

int cmd_count = 6;
char code[100][256];
int counter = 0;

void console() {
    printf("\n Halt os 0.1 version\n \n");
    printf("#   #      #     #    ####### \n");
    printf("#   #    #  #    #        #        Halt Kernel \n");
    printf("#####   #    #   #        #        color bar :\n");
    printf("#   #  ########  #        #\n");
    printf("#   #  #      #  #####    #        ");
    printf("/clr/0x10 /clr/0x20 /clr/0x30 /clr/0x40 /clr/0x50 /clr/0x60 /clr/0x70 /clr/0x80 /clr/0x90 /clr/0xA0 /clr/0xB0 /clr/0xC0 /clr/0xD0 /clr/0xE0 /clr/0xF0 /clr/0x0F\n");

    char command[256];
    int run = 1;

    while (run) {
        printf("uc-/clr/0x02$ /clr/0x0F");
        scanf(command);

        if (command[0] == '\0') continue;

        if (strncmp(4, command, "exit") == 0) {
            printf(" [ Successful end of the session ]\n");
            run = 0;
            continue;
        }

        if (strncmp(4, command, "echo") == 0) {
            printf(command + 5);
            printf("\n");
            continue;
        }

        int found = 0;
        for (int i = 0; i < cmd_count; i++) {
            int name_len = strlen(cmd_table[i].name);
            if (strncmp(name_len, command, cmd_table[i].name) == 0) {
                cmd_table[i].func();
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("/clr/0x04 Unknown command : /clr/0x0F ");
            printf(command);
            printf("\n write <help> : show command system \n ");
            put_char('\n');
        }
    }
}

void uc_editor() {
    clear_screen();
    counter = 0; 
    char line[256];
    int run = 1;
    int line_counter = 1;
    char line_counter_s[5];
    while (run) {
        itoa(line_counter, line_counter_s);
        printf(line_counter_s);
        printf(" | ");
        line_counter++;
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
    char var_value[156];
    int i = 0;
    char line[256];
    while (i < counter) {
        strcpy(line, code[i]);

        if (strncmp(5, line, "echol") == 0) {
            int j = 6;
            while (line[j] != '\0') {
                if (line[j] == '"') {
                    j++;
                    while (j < 251 && line[j] != '"') {
                        put_char(line[j]);
                        j++;
                    }
                } else if (line[j] == 'v') {
                    printf(var_value);
                    j++;
                }
                j++;
            }
        } else if (strncmp(4, line, "echo") == 0) {
            int j = 5;
            while (line[j] != '\0') {
                if (line[j] == '"') {
                    j++;
                    while (j < 251 && line[j] != '"') {
                        put_char(line[j]);
                        j++;
                    }
                } else if (line[j] == 'v') {
                    printf(var_value);
                    j++;
                }
                j++;
            }
            put_char('\n');
        } else if (strncmp(4, line, "goto") == 0) {
            int goto_line = 0;
            int j = 5;
            while (line[j] >= '0' && line[j] <= '9') {
                goto_line = goto_line * 10 + (line[j] - '0');
                j++;
            }
            if (goto_line > 0 && goto_line <= counter) {
                i = goto_line - 1;
                continue; 
            } else {
                printf("Error: Invalid line\n");
            }
        } else if (strncmp(3, line, "let") == 0) {
            int j = 4;
            int k = 0;
            while (line[j] != '\0') {
                if (line[j] == '"') {
                    j++;
                    while (j < 251 && line[j] != '"') {
                        var_value[k] = line[j];
                        j++;
                        k++;
                    }
                }
                j++;
            }
        } else if (strncmp(5, line, "input") == 0) {
            char value_input[256];
            scanf(value_input);
            strcpy(var_value, value_input);
        } else {
            if (line[0] != '\0') {
                printf(" /clr/0x04 syntax error in  /clr/0x0F: \n    > ");
                printf(line);
                printf("\n");
            }
        }
        i++;
    }
}