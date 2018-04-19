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
sem_t sem_tlq1,sem_tlq2;
char buf[128] = {0};

void *fun1(void *s)
{
        sem_wait(&sem_tlq1);
        fgets(buf,sizeof(buf),stdin);
        sem_post(&sem_tlq2);

}

void *fun2(void *s)
{
        sem_wait(&sem_tlq2);
        if(buf[strlen(buf)-1] == '\n')
            buf[strlen(buf)-1] = '\0';
        printf("%s",buf);
        sem_post(&sem_tlq1);

}
int main(char argc,char *argv[])
{
    int p1,p2;
    //char *str = "liuqi";

    if((sem_init(&sem_tlq1,0,1)) == -1)
    {
        perror("sem_tlq fail!");
        exit(1);
    }
    if((sem_init(&sem_tlq2,0,0)) == -1)
    {
        perror("sem_tlq fail!");
        exit(1);
    }
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