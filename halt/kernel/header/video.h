/*
 ===============================================================

 	************************
 	| halt OS (C)          |
 	| 6/2/2026             |
 	| Header file of video |
 	************************

 	set_char('c') print one char
	set_color(0x00) change the color
	display("text") print text or string
	set_x_y(x, y) this set x and y
	clear() clear B800 and write in x=0 y=0
	off_() off cutsor in monitor
	get_x_y() x = ? and y = ?
	get_value(var x y ) copy char in the screen
	rermove_char() remove one char in screen
	display_d(number) print number type int
 ===============================================================

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
void display_d(int number);
