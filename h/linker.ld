ENTRY(_start)

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
