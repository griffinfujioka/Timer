.globl begtext, begdata, begbss                      ! needed by linker

.text                                                ! these tell as:	
begtext:                                             ! text,data,bss segments
.data                                                ! are all the same.
begdata:
.bss
begbss:
.text               
.globl  _main, _syscall, _exit
.globl  _getcs, _color, _getc, _putc


        call _main
	
! if ever return, exit(0)
	push  #0
        call  _exit

_getcs:
        mov   ax, cs
        ret

_syscall:
        int    80
        ret

_getc:
        xorb   ah,ah 
        int    0x16  
        ret 

_putc:           
        push   bp
        mov    bp,sp
        movb   al,4[bp]
        movb   ah,#14  
        mov    bx,#0x000B 
        int    0x10    
        pop    bp
        ret
