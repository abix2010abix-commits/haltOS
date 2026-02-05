#include "header/io_port.h"


unsigned char *monitor = (unsigned char *)0xB8000;

int color = 0x0F;
void cursor_off();

int cursor_x = 0;
int cursor_y = 0;
int cursor = 0;



void cursor_off() {
    unsigned short pos = 80 * 25;

    outb(0x3D4, 14);
    outb(0x3D5, pos >> 8);

    outb(0x3D4, 15);
    outb(0x3D5, pos & 0xFF);
}

void scroll() {
	for(int i = 0; i < 24 * 80; i++) {
		monitor[i * 2] = monitor[(i + 80) * 2];
		monitor[i * 2 + 1] = monitor[(i + 80) * 2 + 1];
	}
	for(int j = 24 * 80; j < 25 * 80; j++) {
		monitor[j * 2] = ' ';
		monitor[j * 2 + 1] = 0x00;
	}
	cursor_y = 24;
}

void remove_char() {
    if (cursor_x > 0) {
		cursor_x--;
    } else if (cursor_y > 0) {
		cursor_y--;
        cursor_x = 79; 
    } else {
        return;
    }

	int index = (cursor_y * 80 + cursor_x) * 2;
    monitor[index] = ' ';
    monitor[index + 1] = 0x07;
}

void put_char(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } 
    else {
        int index = (cursor_y * 80 + cursor_x) * 2;
        monitor[index] = c;
        monitor[index + 1] = (unsigned char)color;
        cursor_x++;
    }

	if (cursor_x >= 80) {
        cursor_x = 0;
        cursor_y++;
    }

    if (cursor_y >= 25) {
        scroll();
    }
}

void clear_screen() {
    cursor_off();
    for(int i = 0; i < 80 * 25; i++) {
		monitor[i * 2] = ' ';
		monitor[i *2 + 1] = 0x00;
	}
    cursor_x = 0;
    cursor_y = 0;
}

int hex_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return 0;
}


void printf(const char *text) {
    while (*text) {
        if (*text == '/' && *(text + 1) == 'c' && *(text + 2) == 'l' && *(text + 3) == 'r' && *(text + 4) == '/') {
            text += 5; 
            if (*text == '0' && *(text + 1) == 'x') {
                text += 2;
                
                int bg = hex_to_int(*text);
                int fg = hex_to_int(*(text + 1)); 
                
                color = (bg << 4) | fg;
                text += 2; 
            }
            continue; 
        } else {
            put_char(*text);
        }

        text++;
    }
}
