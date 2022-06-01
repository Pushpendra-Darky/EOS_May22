#include<stdio.h>
#include<pthread.h>

pthread_t thread_id;

void *display(void *data)
{
   printf("This is Newly Created Thread \n");
}

int main()
{
    printf("Before Thread Creation\n");
    pthread_create(&thread_id,NULL,display,NULL);
    printf("After Thread Creation\n");
    pthread_join(thread_id,NULL);
    return 0;
}