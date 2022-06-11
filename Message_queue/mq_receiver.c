#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>        
#include <sys/stat.h>       
#include <mqueue.h>

#define MSG_SIZE 128
struct mq_attr attr;
mqd_t mq_fd;

unsigned char buffr[MSG_SIZE];
unsigned int priority;

int main()
{
    attr.mq_maxmsg = 4;
    attr.mq_msgsize = MSG_SIZE;
    attr.mq_curmsgs = 0;
    attr.mq_flags = 0;

    mq_fd = mq_open("/IPC_mq",O_CREAT | O_RDWR, S_IRUSR |S_IWUSR|S_IWGRP |S_IRGRP, &attr);

    if (-1 == mq_fd)
    {
        perror("mq_open : Error In Creating Openingg Queue In KS\n");
        exit(EXIT_FAILURE);
    }

    mq_receive(mq_fd, buffr, MSG_SIZE, &priority);
    printf("Message From P1: \nReceived In P2:  %s\n",buffr);

    mq_close(mq_fd);
    return 0;

}