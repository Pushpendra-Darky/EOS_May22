#include<stdio.h>
#include<pthread.h>

int count = 0;

void *inc_thread(void *arg)
{
    while(1)
    {
    count++;
    printf("Inc Thread %d\n",count);
    }
}

void *dec_thread(void *arg)
{
    while(1)
    {
    count--;
    printf("Dec Thread %d\n",count);
    }
}

int main()
{
    pthread_t inc,dec;

    pthread_create(&inc,NULL,inc_thread,NULL);
    pthread_create(&dec,NULL,dec_thread,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);
    return 0;
}