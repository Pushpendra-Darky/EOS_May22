#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<semaphore.h>

int *count = NULL;

int main()
{
    int shm_fd;

    sem_t *count_sem;
    count_sem = sem_open("/shared_shm_sem", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP,1);

    shm_fd = shm_open("/shared_shm",O_CREAT | O_RDWR,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);  // 0660

    if(-1 == shm_fd)
    {
        perror("shm_open: Error In Opening\n");
        return (EXIT_FAILURE);
    }

    ftruncate(shm_fd,sizeof(int));

    count = (int *)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE, MAP_SHARED,shm_fd,0);

    while(1)
    {
        sem_wait(count_sem);

        printf("Data Recieved : By Shared Memory : %d\n",*count);

        sem_post(count_sem);
    }

    sem_close(count_sem);
    
    return 0;
}