#include "header/io_port.h"
#include "header/vga.h"

unsigned char scan_code(void);
unsigned char translate_code(unsigned char sc);

static unsigned char last_code = 0;
static unsigned long long last_time = 0;

unsigned char scan_code() {
    while(!(inb(0x64) & 1));
    return inb(0x60);
}

unsigned char translate_code(unsigned char sc) {
    static unsigned char keyboard_map[] = {
        0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ')', '=', '\b',
        '\t', 'a', 'z', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '"', ']', '\n',
        0,    'q', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ']', '%', '*',
        0,    0,   'w', 'x', 'c', 'v', 'b', 'n', ';', 'm', ':', '!', 0,
        '*',  0,  ' '
    };
    if (sc < 58) return keyboard_map[sc];
    return 0;
}

unsigned char get_char() {
    unsigned char code = scan_code();

    if (code & 0x80) {
        last_code = 0; 
        return 0;
    }

	if (code == last_code) {
        return 0; 
    }

    last_code = code; 

	for(volatile int i = 0; i < 50000; i++); 

    return translate_code(code);
}


void scanf(char *bufer) {
    int i = 0;
    unsigned char c;

    while(1) {
        c = get_char();

        if (c != 0) {

            if (c == '\n' || c == '\r') {
                bufer[i] = '\0';
                put_char('\n');
                return;
            }
            else if (c == '\b' && i > 0) {
                i--;
                remove_char();
            }

			else if (i < 255) { 
                put_char(c);
                bufer[i] = c;
                i++;
            }
        }
    }
}
