

// source :
// github linux xv6 wiki devOS minix telegrame youtyoube
// a = EAX AX AL
// D = EDX DX DL
// B = EBX BX BL
// C = ECX CX CL
// S = ESI SI


// volatile = not touch this line flage red
// __asm__  write assembley code 
// "type"(varibales)
// : : bar asm and value 
// =  == say yo i686-elf-gcc this not sned this receive
// exp == "=a"

// 5/1/2026 20:46 PM
void send_data(unsigned short PORT, unsigned char VALUE) {
    __asm__ volatile ("outb %0, %1" : : "a"(VALUE), "d"(PORT)); // form in github 
}

// ="a" this hard to send_data

// 5/1/2026 21:25 PM
unsigned char receive_data(unsigned short port) {
    unsigned char value;
    __asm__ volatile ("inb %1, %0" : "=a"(value) : "Nd"(port)); // form in reddit
    return value;

}

/*
    ==========================================
    send_data it is very haed i can learn this
    asm file it is basic and easy
    ==========================================
*/

/*
    port and use
    ==========================================
    send 0x70:
        0x00 second
        0x02 minuts
        0x04 hours
    receive 0x71:
        time :  0x00 --> 0x59
                0x00 --> 0x23
    ==========================================
    receive 0x64 :
        click up keybord
    receive 0x60 :
        key click or hex code
    ==========================================
    source :
    github / linux
    github / minix
    gtihub / mikeOS
    github / xv6
    github / NyxOS
    github / kolibriOS
*/