; entry.asm
section .multiboot
align 4
    dd 0x1BADB002
    dd 0x00000000
    dd -(0x1BADB002)

section .text
global _start
extern kmain

_start:
	cli
    call kmain

.hang:
    hlt
    jmp .hang

section .bss
align 16
stack_bottom:
    resb 16384
stack_top:
