ENTRY(_start)

/* source :
 github linux_old xv6 minix3 devOS facebook rdit google
*/

SECTIONS
{
    . = 1M;

    _kernel_start = .;

    .multiboot ALIGN(4K) : { *(.multiboot) }
    .text : { *(.text*) }
    .rodata : { *(.rodata*) }
    .data : { *(.data*) }
    .bss : { *(.bss*) }
}
