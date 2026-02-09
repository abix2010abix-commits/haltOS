/*
 ===============================================================

 	****************************
 	| halt OS (C)              |
 	| 7/2/2026                 |
 	| Header file of  keyboard |
 	****************************


 ===============================================================

*/
unsigned char scan_click_key();
unsigned char tran_code(unsigned code_hex);
int get_char();
void input(char *text);
void input_n(int *number);