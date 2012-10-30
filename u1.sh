echo compiling u1.c... 
bcc -c u1.c
as86 -o u.o u.s
echo linking u.o u1.o mtxlib
ld86 u.o u1.o mtxlib /usr/lib/bcc/libc.a

#mount /dev/fd0 /fd0
#cp a.out /fd0/u1
#cp a.out /fd0/bin/u1
#umount /dev/fd0

mount -o loop mtximage.bin fd0 # mount mtximage.bin in fd0 directory
cp a.out fd0/u1
cp a.out fd0/bin/u1
umount fd0

echo removing .o files
rm *.o 
#echo removing a.out
#rm a.out

echo done u1
