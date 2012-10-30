#include "ucode.c"
int color;

main()
{ 
  
  char name[64]; 
  int pid; 
  int cmd;

  while(1)
  {
    pid = getpid();
    color = 0x000A + (pid % 6);
       
    printf("===================================================================\n");
    printf("I am proc %din U mode. I am running at segment=%x\n",pid, getcs());
    printf("===================================================================\n");
    show_menu();
    printf("enter a command: ");
    gets(name); 
    if (name[0]==0) 
        continue;
    printf("\n"); 

    cmd = find_cmd(name);
    switch(cmd)
    {
          case 0 : getpid();   break;
          case 1 : ps();       break;
          case 2 : chname();   break;
          case 3 : kmode();    break;
          case 4 : kswitch();  break;
          case 5 : wait();     break;
          case 6 : exit();     break;
          case 7 : ufork();    break; 
          case 8 : uexec();    break; 
          case 9 : getProcName(); break;    /* Given a char name[64], return that PROCs pid */ 
          default: invalid(name); break;
    }
  }
}
