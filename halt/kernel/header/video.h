/*
	==========================================
	6 01 2026
	video header file C
	==========================================
	set_char('c') print one char
	set_color(0x00) change the color
	display("text") print text or string
	set_x_y(x, y) this set x and y
	clear() clear B800 and write in x=0 y=0
	off_() off cutsor in monitor
	get_x_y() x = ? and y = ?
	==========================================
*/



void set_char(const char value);
void set_color(int color_value);
void display(const char *value);
void set_x_y(int x_local, int y_local);
void clear();
void off_();
void get_x_y(int *x_local, int *y_local);
void get_value(char *varibel, int x_local, int y_local);
void remove_char();

