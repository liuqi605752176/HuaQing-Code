//
// Created by liuqi on 4/2/18.
//

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
struct student
{
    int age;
    char name[20];
}stu_t;

void *thread_fun(void *stu)
{
    sleep(1);
    printf("student age is %d,name is %s\n",((struct student *)stu)->age,((struct student *)stu)->name);
    return (void *)0;
}

int main(int argc,char *argv[])
{
    pthread_t tid;
    int err;
    int *reval;
    struct  student stu;
    stu.age = 20;
    memcpy(stu.name,"張三",20);

    err = pthread_create(&tid,NULL,thread_fun,(void *)(&stu));
    if(err != 0)
    {
        printf("creat main_thread failed!\n");
        return 0;
    }
    int i;
    for(i =0;i<argc;i++)
    {
        printf("main_thread args[%d] is %s\n",i,argv[i]);
    }
    pthread_exit(&reval);
    return 0;
}