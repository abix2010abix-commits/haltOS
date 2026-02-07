#include "header/io_port.h"

unsigned char *monitor = (unsigned char *)0xB8000;
int color = 0x0F;

// ==========================================
// new dev --> 7/01/2026 20:31 PM
struct {
    int x;
    int y;
}position;
// ==========================================
// 6/1/2026 17:58 PM
// i dev mini bug in 17 M
void set_char(const char value) {
    if (value == '\n') {
        position.x = 0;
        position.y++;
    } else {
        // end x then y+1 x = 0 == new line
        if (position.x >= 80) {
            position.x = 0;
            position.y++;
        }
        // set value in B800
        int index = (position.y * 80 + position.x) * 2;
        monitor[index] = value;
        monitor[index + 1] = (unsigned char)color;
        position.x++;
    }
    if (position.y >= 25) {
            // move line to before line == secroll
            // this hard math
            for (int i = 0; i < 24 * 80; i++) {
                monitor[i * 2] = monitor[(i + 80) * 2];
                monitor[i * 2 + 1] = monitor[(i + 80) * 2 + 1];
            }
            for (int i = 24 * 80; i < 25 * 80; i++) {
                monitor[i * 2] = ' ';
                monitor[i * 2 + 1] = (unsigned char)color;
            }
            position.y = 24;
        }
}


// ==========================================
// 6/1/2026 18:08 PM
void set_color(int color_value) {
    if (color_value == 0x11) return;
    else if (color_value == 0x22) return;
    else if (color_value == 0x33) return;
    else if (color_value == 0x44) return;
    else if (color_value == 0x55) return;
    else if (color_value == 0x66) return;
    else if (color_value == 0x77) return;
    else if (color_value == 0x88) return;
    else if (color_value == 0x99) return;
    else if (color_value == 0xAA) return;
    else if (color_value == 0xBB) return;
    else if (color_value == 0xCC) return;
    else if (color_value == 0xDD) return;
    else if (color_value == 0xEE) return;
    else if (color_value == 0xFF) return;
    else {
        color = color_value;
    }
    
}

// ==========================================
// 6/1/2026 18:26 PM
void display(const char *value) {
    for(int counter = 0; value[counter] != '\0'; counter++) {
        set_char(value[counter]);
    }
}
//==========================================
// 6/1/2026 18:58 PM
void set_x_y(int x_local, int y_local) {
    if (x_local >= 80 && y_local >= 25) return;
    else {
        position.x = x_local;
        position.y = y_local;
    }
}
//==========================================
// 6/1/2026 18:59 PM
void clear() {
    for(int counter = 0; counter < 80 * 25; counter++) {
        monitor[counter * 2] = ' ';
        monitor[counter *2 + 1] = color;
    }
    set_x_y(0, 0);
}
//==========================================
// 6/1/2026 21:50 PM
// i found this in Reddit
// off _ in B8000 or cursor
void  off_() {
    unsigned short pos = 80 * 25;
    send_data(0x3D4, 14);
    send_data(0x3D5, pos >> 8);
    send_data(0x3D4, 15);
    send_data(0x3D5, pos & 0xFF);
}
//==========================================
// 6/1/2026 22:42 PM
void get_x_y(int *x_local, int *y_local) {
    *x_local = position.x;
    *y_local = position.y;
}
// ==========================================
// 7/1/2026 20:18 PM
void get_value(char *varibel, int x_local, int y_local) {
    if (x_local > 80 || y_local > 25) {
        return;
    }
    int index = (y_local * 80 + x_local) * 2;
    char c = monitor[index];
    *varibel = c;
}