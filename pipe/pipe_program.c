#include<stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h>

#define MAX_BUFF_SIZE 11

int main()
{
    unsigned char buff[MAX_BUFF_SIZE];
    pid_t id;

    int pipe_fd[2];      //pipe_fd[0] is for reading
                         //pipe_fd[1] is for writing

    pipe(pipe_fd);      

    id = fork();

    if(id==0)
    {
        close(pipe_fd[1]);
        printf("Child Process\n");
        read(pipe_fd[0],buff,sizeof(buff));
        printf("Child: Received Data: %s\n",buff);
    }
    else
    {
        close(pipe_fd[0]);
        write(pipe_fd[1],"Pushpendra\n",11);
        printf("Parent: Wrote Data\n");
    }

    return 0;
}
