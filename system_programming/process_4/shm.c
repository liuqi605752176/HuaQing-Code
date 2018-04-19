//
// Created by liuqi on 4/6/18.
//

#include <stdio.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
void myfun1(int signum)
{

}
void myfun2(int signum)
{

}


int main()
{
    int shmid;
    int key;
    char *p;
    pid_t pid;
    key = ftok("/home/liuqi/Documents/system_programming/process_4/",'a');
    if(key < 0)
    {
        perror("ftok");
        exit(-1);
    }
    else
        printf("生成Key值成功,key = %d\n",key);

    shmid = shmget(key,128,IPC_CREAT|0777);
    if(shmid == -1)
    {
        if(errno != EEXIST)
        {
            perror("shmget");
            exit(-1);
        }
        else
        {
            shmid = shmget(key,128,0777);
        }

    }
    else
        printf("创建共享内存成功，shmid = %d\n",shmid);
    //system("ipcs -m");
    pid = fork();
    switch(pid)
    {
        case -1:
                perror("fork");
                exit(-1);
        case 0:
            printf("我是子进程！\n");
            printf("读取的共享内存数据：\n");
            p = (char *)shmat(shmid,NULL,0);
            if(p == NULL)
            {
                perror("子进程共享内存映射");
                exit(-1);
            }
            signal(SIGUSR1,myfun1);
            while(1)
            {
                pause();        //等待父进程写入数据
                //开始读取共享内存
                printf("子进程读取共享内存数据:%s\n", p);
                kill(getppid(),SIGUSR2);


            }

        default:
            printf("我是父进程！\n");
            signal(SIGUSR2,myfun2);
            //共享内存映射
            p = (char *)shmat(shmid,NULL,0);
            if(p == NULL)
            {
                perror("父进程共享内存映射");
                exit(-1);
            }
            while(1)
            {
                printf("父进程开始写数据");
                fgets(p,128,stdin);
                kill(pid,SIGUSR1);//通知子进程开始读取数据
                pause();          //等待子进程读
                if(strncmp("quit",p,4) == 0)
                {
                    signal(pid,SIGUSR1);
                    printf("程序已退出！");
                    break;
                }
            }

    }
    
    //memcpy(p,"abcd",4);
    shmctl(shmid,IPC_RMID,NULL);

    return 0;
}