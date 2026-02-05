static inline void outw(unsigned short port, unsigned short data) {
    __asm__ __volatile__ ("outw %w0, %w1" : : "a" (data), "Nd" (port));
}

static inline void outb(unsigned short port, unsigned char value) {
    __asm__ volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

static inline unsigned char inb(unsigned short port) {
	unsigned char ret;
	__asm__ volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
	return ret;
}


