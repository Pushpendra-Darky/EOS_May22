#include<stdio.h>
#include<pthread.h>

pthread_t thread_id; // for thread id

void *display(void *data)
{
   printf("This Thread Is Not Executing Because Main Thread End in Main\n");
}

int main()
{
    printf("Before Thread Creation\n");
    pthread_create(&thread_id,NULL,display,NULL);
    //sleep(2); if we use sleep it execute display thread
    printf("After Thread Creation\n");
    return 0;
}