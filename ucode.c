// ucode.c file

char *cmd[]={"getpid", "ps", "chname", "kmode", "switch", "wait", "exit", "ufork", "uexec", "getProcName", 0};

int show_menu()
{
   printf("************************ Menu ***********************************\n");
   printf("* getpid  ps  chname  kmode  switch  wait  exit  ufork  uexec   *\n");
   /*         0      1     2      3       4      5     6      7     8  */
   printf("******************************************************************\n");
}

int find_cmd(name) char *name;
{
   int i=0;   
   char *p=cmd[0];

   while (p)
   {
         if (strcmp(p, name)==0)
         {
               
              return i; 
         }
            
         i++;  
         p = cmd[i];
   } 
   return(-1);
}



int getpid()
{
   return syscall(0,0,0); /* call getpid() in Kernel */ 
}

int ps()
{
   syscall(1, 0, 0);
}

int chname()
{
    char s[32];
    printf("input new name : ");
    gets(s);
    printf("\nchanging running->name to %s\n", s);
    syscall(2, s, 0);
}

int kmode()
{
    printf("kmode : syscall #3 to enter Kmode\n");
    printf("proc %d going K mode ....\n", getpid());
    syscall(3, 0, 0);
    printf("proc %d back from Kernel\n", getpid());
}    

int kswitch()
{
    printf("proc %d enter Kernel to switch proc\n", getpid());
        syscall(4,0,0);
    printf("proc %d back from Kernel\n", getpid());
}

int wait()
{
    int child, exitValue = 0; 
    printf("proc %d enter Kernel to wait for a child to die\n", getpid());
    child = syscall(5, &exitValue, 0);
    printf("proc %d back from wait, dead child=%d", getpid(), child);
    if (child>=0)
        printf("exitValue=%d", exitValue);
    printf("\n"); 
} 

int exit()
{
   char exitValue;
   printf("\nenter an exitValue (0-9) : ");
   exitValue=getc() - '0';    /* convert to integer value */ 
   printf("entering kernel to die with exitValue=%d\n", exitValue);
        syscall(6,exitValue,0);
}

int ufork()
{
  int child;
  child = syscall(7,0,0,0);
  if (child)
    printf("parent %d return form fork, child=%d\n", getpid(), child);
  else
    printf("child %d return from fork, child=%d\n", getpid(), child);
}

int uexec()
{
  int r;
  char filename[32];
  printf("enter exec filename : ");
  gets(filename);
  r = syscall(8,filename,0,0);
  printf("exec failed\n");
}

int invalid(name) char *name;
{
    printf("Invalid command : %s\n", name);
}


int getProcName()
{
  int r; 
  char name[64];
  printf("enter name: ");
  gets(name); 
  r = syscall(9, name, 0,0); 

}