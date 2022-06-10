#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,unsigned char argv[])
{
    pid_t id;

    unsigned char cmd[100];


for(;;)
{
    
    printf("Darky@Shell $ : ");
    scanf("%s",cmd);

    id = fork();
    if(id==0)
    {

       // printf("\nIN CHILD PROCESS\n");
        //printf("Child  Process: ID: %d PPID: %d\n",getpid(),getppid());
        execlp(cmd,cmd,NULL);          
        
        
    }
    else if(id>1)
    {
       // printf("IN PARENT PROCESS\n");
       // printf("Parent Process: ID: %d PPID: %d\n",getpid(),getppid());
        wait(NULL);
          

    }
    else
    {
        printf("\nFork Failed\n");
    }

   
    
}

    return 0;
}