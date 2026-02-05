#include "header/io_port.h"
#include "header/string.h"

void get_second(char *t_scond) {
   outb(0x70, 0x00);
   int basic_second = (int)inb(0x71);
   int new_second = (basic_second & 0x0F) + ((basic_second >> 4) * 10);
   itoa(new_second, t_scond);
}

void get_minut(char *t_scond) {
   outb(0x70, 0x02);
   int basic_second = (int)inb(0x71);
   int new_second = (basic_second & 0x0F) + ((basic_second >> 4) * 10);
   itoa(new_second, t_scond);
}

void get_hours(char *t_scond) {
   outb(0x70, 0x04);
   int basic_second = (int)inb(0x71);
   int new_second = (basic_second & 0x0F) + ((basic_second >> 4) * 10);
   itoa(new_second, t_scond);
}

