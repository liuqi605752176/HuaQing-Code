//
// Created by liuqi on 4/4/18.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#if 0
typedef struct shmemory
{
    char buf[128];
    int flag1;
    int flag2;
}SHM;

int main()
{
    key_t key;
    int shmid;
    key = ftok("/home/liuqi/Documents/system_programming/process_4/",'a');
    if(key == -1)
    {
        perror("ftok");
        exit(-1);
    }
    shmid = shmget(key, 128,IPC_CREAT|IPC_EXCL|0664);
    if(shmid == -1)
    {
        if(errno != EEXIST)
        {
            perror("shmget");
            exit(-1);
        }
        else
        {
            shmid = shmget(key,128,0664);
        }
    }

        SHM *shm = shmat(shmid, NULL, 0);
        if (shm == (void *) -1) {
            perror("shmat");
            exit(-1);
        }
        shm->flag1 = 1;
        shm->flag2 = 0;
    while(1)
    {
        if(shm->flag1 == 1)
        {
            fgets(shm->buf, 128, stdin);
            shm->buf[strlen(shm->buf) - 1] = '\0';
            shm->flag1 = 0;
            shm->flag2 = 1;
            if(strncmp("quit",shm->buf,4) == 0)
            {
                break;
            }
        }
    }
}

#endif

typedef struct shmemory
{
    char buf[128];
    pid_t pid1;
    pid_t pid2;
}SHM;

void *fun()
{

}

int main()
{
    key_t key;
    int shmid;
    signal(SIGUSR1,fun);
    key = ftok("/home/liuqi/Documents/system_programming/process_4/",'a');
    if(key == -1)
    {
        perror("ftok");
        exit(-1);
    }
    shmid = shmget(key, 128,IPC_CREAT|IPC_EXCL|0664);
    if(shmid == -1)
    {
        if(errno != EEXIST)
        {
            perror("shmget");
            exit(-1);
        }
        else
        {
            shmid = shmget(key,128,0664);
        }
    }

    SHM *shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        exit(-1);
    }
    shm->pid1 = getpid();
    while(1)
    {
            fgets(shm->buf, 128, stdin);
            shm->buf[strlen(shm->buf) - 1] = '\0';
            kill(shm->pid2,SIGUSR1);


    }
}