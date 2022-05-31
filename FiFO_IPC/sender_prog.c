#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    int S_Wfd;

    S_Wfd = open("fifo_namedpipe_IPC_file",O_WRONLY);
    write(S_Wfd,"This is FIFO IPC\n",18);
    close(S_Wfd);
    return 0;

}
