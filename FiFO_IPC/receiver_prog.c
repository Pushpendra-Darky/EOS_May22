#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    unsigned char buff[18];
    int R_Rfd;

    R_Rfd = open("fifo_namedpipe_IPC_file",O_RDONLY);
    read(R_Rfd,buff,18);
    printf("Read Data:%s",buff);
    close(R_Rfd);
    return 0;
}
