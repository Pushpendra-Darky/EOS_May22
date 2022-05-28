#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;

    printf("Before Fork Calling\n");
    id = fork();
    printf("After Fork Called Print twice 1st for Parent & 2nd For Child\n");
    return 0;
}