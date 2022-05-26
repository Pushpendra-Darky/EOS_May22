#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd;
    char str[12]="PUSHPENDRA\n";
    fd = open("file.txt", O_CREAT | O_RDONLY);
    if(-1== fd)
    {
        //perror("ERROR IN OPENING FILE\n");
        printf("FIle is already exists\n");
        printf("file Content %s\n",str);
        exit(1);
    }
  //  char str[12]="PUSHPENDRA\n";
    read(fd,str,12);

    write(fd,str,12);
    printf("file content %s\n",str);
    close(fd);
    return 0;
}