#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int main()
{
    int fd;
    fd = open("file.txt", O_CREAT | O_WRONLY);
    if(-1== fd)
    {
        perror("ERROR IN OPENING FILE\n");
    }
    write(fd,"DESD HYDERABAD\n",15);
    close(fd);
    return 0;
}