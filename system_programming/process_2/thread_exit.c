//
// Created by liuqi on 4/2/18.
//

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_fun(void *arg)
{
    if(strcmp("1",(char *)arg) == 0)
    {
        printf("return !\n");
        return (void *)1;
    }
    if(strcmp("2",(char *)arg) == 0)
    {
        printf("pthread_exit!\n");
        pthread_exit((void *)2);
    }
    if(strcmp("3",(char *)arg) == 0)
    {
        printf("exit!\n");
        exit(3);
    }
}

int main(int argc,char *argv[])
{
    int err;
    pthread_t  tid;

    err = pthread_create(&tid,NULL,thread_fun,(void *)argv[1]);
    if(err != 0)
    {
        printf("create failed\n");
        return 0;
    }
    sleep(1);
    printf("main thread\n");
    return 0;
}