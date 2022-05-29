#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;

    printf("Before Fork Calling\n");
    id = fork();
    if(0==id)
    {
        printf("Child  Process: ID: %d PPID: %d\n",getpid(),getppid());
        sleep(10);
        printf("Child  Process: ID: %d PPID: %d\n",getpid(),getppid());
        printf("Child Completed\n");
    }
    else if(0<id)
    {
        printf("Parent Process: ID: %d PPID: %d\n",getpid(),getppid());
        printf("Parent Completed");
    }
    else
    {
        printf("\nFork Failed\n");
    }
    return 0;
}