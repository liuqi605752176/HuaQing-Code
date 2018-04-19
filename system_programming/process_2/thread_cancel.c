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
    int stateval;
    int typeval;
    stateval = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
    if(stateval != 0)
    {
        printf("設置取消狀態失敗!\n");
    }
    printf("我是新線程!\n");
    sleep(4);
    printf("about to cancel!\n");
    stateval = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
    if(stateval != 0)
    {
        printf("設置取消狀態失敗!\n");
    }
    typeval = pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
    if(typeval != 0)
    {
        printf("設置取消類型失敗!\n");
    }
    printf("first cancel point\n");
    printf("second cancel point\n");

    pthread_exit((void *)20);
}

int main()
{
    pthread_t tid;
    int err;
    int cval,jval;
    void *rval;

    err = pthread_create(&tid,NULL,thread_fun,NULL);
    if(err != 0)
    {
        printf("創建線程失敗!\n");
        return 0;
    }
    sleep(2);
    cval = pthread_cancel(tid);
    if(cval != 0)
    {
        printf("取消線程失敗!\n");
    }
    jval = pthread_join(tid,&rval);

    printf("新線程退出碼：%d\n",(int *)rval);

}