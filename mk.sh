echo compiling ts.s t.c... 
bcc -c t.c
as86 -o ts.o ts.s
echo linking ts.o t.o mtxlib...
ld86 -d ts.o t.o mtxlib /usr/lib/bcc/libc.a


mount -o loop mtximage.bin fd0	# mount mtximage.bin in fd0 directory, which I created 
cp a.out fd0/boot/mtx

#Create user mode image 1
echo compiling u.s u1.c 
bcc -c u1.c
as86 -o u.o u.s
echo linking u.o u1.o 
ld86 u.o u1.o /usr/lib/bcc/libc.a
# a new a.out has been generated and will be used as user mode image 
cp a.out fd0/u1
cp a.out fd0/bin/u1

umount fd0

rm *.o a.out
echo done!
