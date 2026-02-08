/*
	==========================================
	io_port header file
	send_data(0x00, 0x00)
	          port, value

	==========================================
*/

void send_data(unsigned short PORT, unsigned char VALUE);
unsigned char receive_data(unsigned short port);