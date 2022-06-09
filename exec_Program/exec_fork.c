#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,unsigned char argv[])
{
    pid_t id;

    printf("Before Fork Calling\n");

    id = fork();
    if(id==0)
    {

        printf("\nIN CHILD PROCESS\n");
        printf("Child  Process: ID: %d PPID: %d\n",getpid(),getppid());
        printf("Calling exec : Executing thread_prog\n\n");
        execlp("/home/darky/CDAC/PGDESD/EOS_May22/exec Program/thread_prog","/home/darky/CDAC/PGDESD/EOS_May22/exec Program/thread_prog",NULL);
    }
    else if(id>1)
    {
        printf("IN PARENT PROCESS\n");
        printf("Parent Process: ID: %d PPID: %d\n",getpid(),getppid());
        wait(NULL);
    }
    else
    {
        printf("\nFork Failed\n");
    }
    return 0;
}