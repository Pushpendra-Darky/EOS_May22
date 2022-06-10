#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int event = 0;

pthread_mutex_t event_mutex;

pthread_cond_t event_cv;

void *waiting_thread(void *data)
{
    printf("Waiting Thread    : Grabbing The Mutex\n");
    pthread_mutex_lock(&event_mutex);
    printf("Waiting Thread    : Got The Mutex\n");

    while(event != 1)
    {
    printf("Waiting Thread    : Waiting With cond_var\n");

    pthread_cond_wait(&event_cv,&event_mutex);

    printf("Waiting Thread    : Got The cond_var\n");
    }

    printf("Waiting Thread    : Event Is 1, So I'am Done\n");
    // some code for functionality

    pthread_mutex_unlock(&event_mutex);
}

void *fire_event_thread(void *data)
{
    printf("Fire Event Thread : Grabbing The Mutex\n");
    pthread_mutex_lock(&event_mutex);

    pthread_cond_signal(&event_cv);

    printf("Fire Event Thread : Signalled The cond_var\n");

    event = 1;    //cr

    pthread_mutex_unlock(&event_mutex);
}

int main()
{
    pthread_t waiting_thread_id,fire_event_thread_id;

    pthread_mutex_init(&event_mutex,NULL);

    pthread_create(&waiting_thread_id,NULL,waiting_thread,NULL);
    pthread_create(&fire_event_thread_id,NULL,fire_event_thread,NULL);

    pthread_join(waiting_thread_id,NULL);
    pthread_join(fire_event_thread_id,NULL);

    pthread_mutex_destroy(&event_mutex);
}