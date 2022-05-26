#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
    int fd;
    fd = open("desd.txt", O_CREAT | O_WRONLY);
    if(-1== fd)
    {
        perror("ERROR IN OPENING FILE\n");
        exit(EXIT_FAILURE);
    }
    write(fd,"DESDHYD\n",8);
    close(fd);
    exit(EXIT_SUCCESS);
    //return 0;
}
