//
// Created by liuqi on 4/3/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t  tid1,tid2,tid3;
pthread_mutex_t mutex;
pthread_cond_t tiaojian1,tiaojian2;

void *thread_fun1()
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&tiaojian1,&mutex);
        printf("hello linux!\n");
        pthread_mutex_unlock(&mutex);
    }
}

void *thread_fun2()
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&tiaojian2,&mutex);
        printf("hello world!\n");
        pthread_mutex_unlock(&mutex);
    }
}

void *thread_fun3()
{
    int a;
    while(1)
    {
        scanf("%d",&a);
        if(a == 0)
        {
            pthread_cond_signal(&tiaojian1);
        }
        if(a == 1)
        {
            pthread_cond_signal(&tiaojian2);
        }
    }
}

int main(int argc,char *argv[])
{
    pthread_cond_init(&tiaojian1,NULL);
    pthread_cond_init(&tiaojian2,NULL);

    pthread_mutex_init(&mutex,NULL);

    pthread_create(&tid1,NULL,thread_fun1,NULL);
    pthread_create(&tid2,NULL,thread_fun2,NULL);
    pthread_create(&tid3,NULL,thread_fun3,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    return 0;
}
