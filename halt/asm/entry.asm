; ========================================
; programmer : souage ahmed el fatih
; os name : haltOS
; ========================================

section .multiboot
align 4
    dd 0x1BADB002 ; magic number of GRUB
    dd 0x00000000
    dd -(0x1BADB002)

section .text
global _start
extern kernel
; ========================================
_start:
    mov esp, stack_top
    call kernel

.hang:
    hlt
    jmp .hang
; ========================================
section .bss
align 16
stack_bottom:
    ; size of stack is 32KB
    resb 32768
stack_top:
