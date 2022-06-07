#include<stdio.h>
#include<pthread.h>

int count=0;

pthread_rwlock_t count_rd_wr_lock;

void *reader_thread1(void *data)
{
    int z;

    pthread_rwlock_rdlock(&count_rd_wr_lock);

    printf("\nReader 1: Inside Critical Region\n");
    z = count+10;
    printf("Reader 1: Value %d, & Count Value: %d\n",z,count);

    pthread_rwlock_unlock(&count_rd_wr_lock);
    printf("Reader 1: Left Critical Region\n");
}

void *reader_thread2(void *data)
{
    int x;
    pthread_rwlock_rdlock(&count_rd_wr_lock);

    printf("\nReader 2: Inside The Critical Region\n");
    x = count+20;
    printf("Reader 2: Value %d, Count Value: %d\n",x,count);

    pthread_rwlock_unlock(&count_rd_wr_lock);
    printf("Reader 2; Left The Critical Region\n");
}

void *writer_thread1(void *data)
{
    printf("\nWriter 1: Entering Critical Region\n");

    pthread_rwlock_wrlock(&count_rd_wr_lock);
    printf("Writer 1: Inside The Critical Region\n");

    count++;

    pthread_rwlock_unlock(&count_rd_wr_lock);
    printf("Writer 1: Left The Critical Region\n");
}


int main()
{
    pthread_t r1,r2,w1;

    pthread_rwlock_init(&count_rd_wr_lock,NULL);

    pthread_create(&r1,NULL,reader_thread1,NULL);
    pthread_create(&r2,NULL,reader_thread2,NULL);
    pthread_create(&w1,NULL,writer_thread1,NULL);

    pthread_join(r1,NULL);
    pthread_join(r2,NULL);
    pthread_join(w1,NULL);

    pthread_rwlock_destroy(&count_rd_wr_lock);

    return 0;
}