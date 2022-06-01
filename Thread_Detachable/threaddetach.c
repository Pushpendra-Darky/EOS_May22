#include<stdio.h>
#include<pthread.h>

pthread_t tid;
pthread_attr_t attr;

void *display(void *data)
{
    printf("This Is Detachable Thread\n");
}

int main()
{
    pthread_attr_init(&attr);  //default attributes

    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED); //set attributes- thread detach state
    
    printf("Before Thread Creation\n");

    pthread_create(&tid,&attr,display,NULL);

    pthread_attr_destroy(&attr);
    printf("After Thread Creation\n");

    pthread_join(tid,NULL);

    return 0;
}