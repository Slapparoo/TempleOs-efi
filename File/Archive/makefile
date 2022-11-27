

reader: reader.c utils.c
	gcc utils.c reader.c -o reader

writer: writer.c utils.c
	gcc utils.c writer.c -o writer -lm

dumpblobby: blobby0.bin blobby1.bin
	objdump -b binary -m i386:x86-64 -D -M intel blobby0.bin
	objdump -b binary -m i386:x86-64 -D -M intel blobby1.bin

dumpelf:
	objdump -afx VeryBasic.efi 
	hexdump -Cv VeryBasic.efi 		

clean:
	rm -f *.o reader writer