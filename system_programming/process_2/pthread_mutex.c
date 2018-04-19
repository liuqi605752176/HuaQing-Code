//
// Created by liuqi on 4/2/18.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>

pthread_t tid1,tid2;
pthread_mutex_t mutexlq;



void *fun1(void *s)
{
    while(1)
    {
        pthread_mutex_lock(&mutexlq);
        printf("hello world\n");
        sleep(1);
        pthread_mutex_unlock(&mutexlq);

    }

}

void *fun2(void *s)
{
    while(1)
    {
        pthread_mutex_lock(&mutexlq);
        printf("hello linux\n");
        sleep(1);
        pthread_mutex_unlock(&mutexlq);
    }


}
int main(char argc,char *argv[])
{
    int p1,p2;
    //char *str = "liuqi";
    pthread_mutex_init(&mutexlq,NULL);

    p1 = pthread_create(&tid1,NULL,fun1,NULL);
    p2 = pthread_create(&tid2,NULL,fun2,NULL);

    if(p1 != 0)
    {
        printf("pthread_creat fail\n");
        exit(1);
    }
    if(p2 != 0)
    {
        printf("pthread_creat fail\n");
        exit(1);
    }
    if((pthread_join(tid1,NULL)) != 0)
    {
        exit(1);
    }

    if((pthread_join(tid2,NULL)) != 0)
    {
        exit(1);
    }

}