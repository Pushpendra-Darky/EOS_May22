#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid_t ppid;

    pid=getpid();
    ppid=getppid();

    printf("PARENT PROCESS ID: %d\n",ppid);
    printf("PROCESS ID: %d\n",pid);

    return 0;
}