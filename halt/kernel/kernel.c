#include "header/video.h"
#include "header/keyboard.h"
#include "header/string.h"
/*
 ===============================================================

 	*************************
 	| halt OS (C)           |
 	| 6/2/2026              |
 	| source file of kernel |
 	*************************


 ===============================================================

*/
void init_driver();

void kernel() {
	init_driver();
	int age;
	input_n(&age);
	if (age == 13) {
		display("hi \n");
	}
	display_d(age);
}

// ==========================================
// 6/1/2026 22:49
// ========================================
void init_driver() {
	clear();
	// ========================================
	set_color(0x0E);
	display("halt = ");
	set_color(0x02);
	display("kernel check diver : \n");
	{
		set_x_y(0, 1);
		int x, y;
		get_x_y(&x, &y);
		if (x != 0 && y != 1) {
			set_color(0x04);
			display("can't update x potion of memory");
			set_color(0x0F);
			return;
		}
		off_();
		set_color(0x0F);
		display("[");
		set_color(0x02);
		display(" OK ");
		set_color(0x0F);
		display(" ] memory video and function \n");
	}
	// ==========================================
	// block keyboard
	// ==========================================
	{
		display("please click key to test driver \n");
		get_char();
		set_color(0x0F);
		display("[");
		set_color(0x02);
		display(" OK ");
		set_color(0x0F);
		display(" ] keyboard port input and output work \n");

	}
	clear();
}

