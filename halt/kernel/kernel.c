#include "header/video.h"
#include "header/keyboard.h"
void init_driver();

void kernel(void) {
	
	init_driver();

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
		if (x && y != 1) {
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
		display(" ] memory video and function");
	}
	// ==========================================
	// block keyboard
	{}

}

