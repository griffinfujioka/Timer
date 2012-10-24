bcc -c t.c
as86 -o ts.o ts.s
ld86 -d ts.o t.o mtxlib /usr/lib/bcc/libc.a

mount -o loop /root/dosemu/mtximage A
cp a.out A/boot/mtx
umount A

rm *.o a.out
echo done mtx
