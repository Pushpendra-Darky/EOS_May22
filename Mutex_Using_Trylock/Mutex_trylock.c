#include<stdio.h>
#include<pthread.h>

int count = 0;
pthread_mutex_t mutex_count;

void *inc_thread(void *arg)
{
    while(1)
    {

    pthread_mutex_lock(&mutex_count);
    count++;
    printf("Inc: Sleeping\n");
    sleep(2);
    printf("Inc Thread %d\n",count);
    pthread_mutex_unlock(&mutex_count);

    }
}

void *dec_thread(void *arg)
{
   int res = 0;
    while(1)
    {
    res = pthread_mutex_trylock(&mutex_count);
    printf("Result: %d",res);

    if(0 == res)
    {
    printf("Lock Available\n");
    count--;
    printf("Dec Thread %d\n",count);
    pthread_mutex_unlock(&mutex_count);
    }
    else
    {
        printf("\nUsed TryLock: Lock Not Available\n");
    }

    }
}

int main()
{
    pthread_t inc,dec;

    pthread_mutex_init(&mutex_count,NULL);

    pthread_create(&inc,NULL,inc_thread,NULL);
    pthread_create(&dec,NULL,dec_thread,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);

    pthread_mutex_destroy(&mutex_count);
    
    return 0;
}