#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *serial_port_thread(void *data)
{
    printf("Serial Port Thread  : Init Started\n");
    sleep(7);  //Emulating Serial Port Initialization
    printf("Serial Port Thread  : Init Finished\n");
    printf("Serial Port Thread  : Main Functionality\n");
}

void *ethernet_thread(void *data)
{
    printf("Ethernet Thread     : Init Started\n");
    sleep(10);  //Emulating Ethernet Port Initialization
    printf("Ethernet Thread     : Init Finished\n");
    printf("Ethernet Thread     : Main Functionality\n");
}

void *lcd_thread(void *data)
{
    printf("LCD Port Thread     : Init Started\n");
    sleep(2);  //Emulating LCD Initialization
    printf("LCD Port Thread     : Init Finished\n");
    printf("LCD Port Thread     : Main Functionality\n");
}

int main()
{
    pthread_t serial_thread_id,ether_thread_id,lcd_thread_id;

    pthread_create(&serial_thread_id,NULL,serial_port_thread,NULL);
    pthread_create(&ether_thread_id,NULL,ethernet_thread,NULL);
    pthread_create(&lcd_thread_id,NULL,lcd_thread,NULL);

    
    pthread_join(serial_thread_id,NULL);
    pthread_join(ether_thread_id,NULL);
    pthread_join(lcd_thread_id,NULL);

    return 0;
}