#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int a,b;
sem_t s1, s2;

void* inputThread(void* data)
{
    while(1)
    {
        sem_wait(&s1);
        printf("Enter two numbers :");
        scanf("%d %d", &a, &b);
        sem_post(&s2);
        sem_post(&s2);
    }
}

void* processingThread(void* data)
{
    while(1)
    {
        sem_wait(&s2);
        sem_wait(&s2);

        int sum=0;
        sum = a+b;
        printf("Sum : %d\n", sum);
        sem_post(&s1);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t inputTid, processingTid;
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 1);
    pthread_create(&inputTid, NULL, inputThread, NULL);
    pthread_create(&processingTid, NULL, processingThread, NULL);
    pthread_join(inputTid, NULL);
    pthread_join(processingTid, NULL);
    sem_destroy(&s1);
    sem_destroy(&s2);
    return 0;
}