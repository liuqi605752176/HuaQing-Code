//
// Created by liuqi on 4/2/18.
//

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <asm/errno.h>

void *thread_fun(void *arg)
{
    sleep(1);
    printf("我是新線程！\n");
    return (void *)0;
}

int main()
{
    pthread_t tid;
    int err;
    int s;
    void *rval;


    err = pthread_create(&tid,NULL,thread_fun,NULL);
    if(err != 0)
    {
        printf("創建新線程失敗\n");
        return -1;
    }
    //sleep(1);
    s = pthread_kill(tid,SIGQUIT);
    if(s == ESRCH)
    {
        printf("新線程沒有發現！\n");
    }
    pthread_join(tid,&rval);
    printf("我是主線程\n");
    return 0;
}