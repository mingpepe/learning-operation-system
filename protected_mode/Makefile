all:
	nasm test.asm -o test.com
	bximage -mode=create -fd=1.44M -q floppy.img
write_test_com:
	# sudo mkdir /mnt/floppy
	sudo mount floppy.img /mnt/floppy
	# Must format floppy.img in FreeDos
	sudo cp test.com /mnt/floppy
	sudo umount /mnt/floppy
clean:
	rm test.com floppy.img