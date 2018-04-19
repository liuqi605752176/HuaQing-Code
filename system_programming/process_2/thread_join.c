//
// Created by liuqi on 4/2/18.
//

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_fun1(void *arg)
{
    printf("我是線程1!\n");
    return (void *)1;
}

void *thread_fun2(void *arg)
{
    printf("我是線程2!\n");
    //pthread_detach(pthread_self());
    pthread_exit(arg);
}

int main()
{
    int err1,err2;
    pthread_t tid1,tid2;
    void *rval1,*rval2;
    char *str = "hello liuqi!\n";
    err1 = pthread_create(&tid1,NULL,thread_fun1,NULL);
    err2 = pthread_create(&tid2,NULL,thread_fun2,str);
    if(err1 || err2)
    {
        printf("創建線程失敗!\n");
        return 0;
    }
    printf("我是主線程!\n");
    printf("等待線程1返回值：%d\n",pthread_join(tid1,&rval1));
    printf("等待線程2返回值：%d\n",pthread_join(tid2,&rval2));


    printf("線程1退出碼： %d\n",(int *)rval1);
    printf("線程2退出碼： %s\n",(char *)rval2);
    printf("我是主線程!\n");

    return 0;
}