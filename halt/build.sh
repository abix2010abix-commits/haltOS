
echo "------------------"
echo "entry.asm"
nasm -f elf32 boot/entry.asm -o elf/entry.osx

cd elf
echo "kernel.o :"
echo "===================="
i686-elf-gcc -m32 -ffreestanding -c ../kernel/*.c
cd ..
echo "linker kernel.elf :"
echo "===================="
i686-elf-ld -m elf_i386 -T linker.ld elf/*.o  -o halt.elf
echo "run in sumlator :"
echo "===================="
qemu-system-i386 -kernel halt.elf
