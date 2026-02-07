mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o halt_os.iso .
echo "===================="
qemu-system-i386 -cdrom halt_os.iso