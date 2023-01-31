all:
	nasm hello.asm -o hello.bin
	bximage -mode=create -fd=1.44M -q floppy.img
	dd if=hello.bin of=floppy.img bs=512 count=1 conv=notrunc
clean:
	rm hello.bin floppy.img