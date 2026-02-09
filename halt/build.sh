rm -r halt_os.iso
echo "------------------"
echo "entry.asm"
nasm -f elf32 asm/entry.asm -o elf/entry.o

cd elf
echo "========================================"
echo "\e[32m compiler to object file :"
echo "========================================"
i686-elf-gcc -m32 -ffreestanding -c ../kernel/*.c
cd ..
echo "========================================"
echo "linker kernel.elf :"
echo "========================================"
i686-elf-ld -m elf_i386 -T linker.ld elf/*.o  -o iso/boot/halt.elf
echo "run in sumlator :"
cd iso

mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o ../halt_os.iso .
cd ..
qemu-system-i386 -cdrom halt_os.iso