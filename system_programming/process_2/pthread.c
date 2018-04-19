//
// Created by liuqi on 4/2/18.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

pthread_t tid1,tid2;

char *retval1 = "retval1";
char *retval2 = "retval2";

void *fun1(void *ret)
{

    printf("hello world!\n");
    printf("%s\n",(char *)ret);
    sleep(10);
    pthread_exit(retval1);
}

void *fun2(void *ret)
{

    printf("hello linux!\n");
    pthread_cancel(tid1);
    pthread_exit(&retval2);
}
int main()
{
    int p1,p2;
    char *str = "liuqi";
    p1 = pthread_create(&tid1,NULL,fun1,str);
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
    if((pthread_join(tid1,&retval1)) != 0)
    {
        exit(1);
    }

    if((pthread_join(tid2,&retval2)) != 0)
    {
        exit(1);
    }

}