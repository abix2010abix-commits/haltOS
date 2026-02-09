#include "header/io_port.h"
#include "header/video.h"
#include "header/string.h"
// ========================================
// keyboard driver 7/1/2026
// ========================================
#define value_true 0x01

// 0x64 sand if key = click
// 			 if key = not click
// 0x60 send hex code for key
// github NyxOS
// github mikeOS
// ========================================
// 7/1/2026 23:20 PM
unsigned char scan_click_key() {
	while(1) {
		if (receive_data(0x64) & value_true) {
			unsigned char scan_code = receive_data(0x60);
			return scan_code;
		}
	}
	return 0;
}
// map of keyboared ps2 
// observation : i found this in github
// but my keyboad different this map so i edit some keys
// i don't copy ; i edit
static unsigned char keyboard_map[] = {
        0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ')', '=', '\b',
        '\t', 'a', 'z', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '"', ']', '\n',
        0,    'q', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ']', '%', '*',
        0,    0,   'w', 'x', 'c', 'v', 'b', 'n', ';', 'm', ':', '!', 0,
        '*',  0,  ' '
};
unsigned char tran_code(unsigned code_hex) {
	return keyboard_map[code_hex];
}
// 8/2/2026 21:37
int get_char() {
	unsigned char value_code;
	do {
		value_code = scan_click_key();
	} while (value_code >= 0x80); // if key > map then loop

	char value = tran_code(value_code);
	return value;
}
// 8/2/2026 22:11
void input(char *text) {
	int piont_counter = 0;
	unsigned char value_char;
	while (1) {
		value_char = get_char();
		if (value_char != 0 ) {
			if (value_char == '\n') {
				text[piont_counter] = '\0';
				set_char('\n');
				break;
			}
			else if (value_char == '\b') {
				if (piont_counter >= 0) {
					piont_counter--;
					remove_char();
				}
			}
			else {
				text[piont_counter] = value_char;
				piont_counter++;
				set_char(value_char);
			}
		}
	}
}
// ===============================================================
//
void input_n(int *number) {
	char text[11];
	input(text);
	*number = str_si(text);
}