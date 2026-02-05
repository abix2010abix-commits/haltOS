#include "header/vga.h"
#include "header/keybord.h" 
#include "header/string.h"
#include "header/time.h"
#include "header/io_port.h"

void shell_help() {
    printf("welcome to halt os you can use this command : \n");
    printf(" ---------------------------------------------\n");
    printf(" 1- help     : show command in uc terminal\n");
    printf(" 2- clear    : remove screen \n");
    printf(" 3- echo     : you can print text in screen\n");
    printf(" 4- editor   : open mini editor and basic lang\n");
    printf(" 5- time     : show time \n");
    printf(" 6- shutdown : power off \n");
    printf(" ---------------------------------------------\n");
}

void shell_about() {
    printf("\n/clr/0x0B --- Halt OS Information --- /clr/0x0F\n");
    printf("Version: /clr/0x0E 0.1 (Stable)/clr/0x0F\n");
    printf("Developer: /clr/0x0A souag ahmed el fatih /clr/0x0F\n");
    printf("Kernel Type: Halt Kernel\n");
    printf("Architecture: x86 (32-bit)\n");
    printf("-----------------------------------\n\n");
}

void shell_time() {
    char minut[3], hours[3], second[3];
    get_second(second);
    printf(second);
    put_char(':');
    get_minut(minut);
    printf(minut);
    put_char(':');
    get_hours(hours);
    printf(hours);
    printf(" GMT \n");
}

void shell_shutdown() {
    printf(" halt _ OS down ... ");
    outw(0x604, 0x2000);
}
