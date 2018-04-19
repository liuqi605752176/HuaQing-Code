//
// Created by liuqi on 4/8/18.
//

#include <apeu.h>


//信号量初始化
int mysem_init(int sem_id,int val)
{
    union semun
    {
        int              val;    /* Value for SETVAL */
        struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
        unsigned short  *array;  /* Array for GETALL, SETALL */
        struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
    }sem_union;
    sem_union.val = val;
    if((semctl(sem_id,0,SETVAL,sem_union))==-1)
    {
        perror("init fail");
        exit(-1);
    }
    return 0;

}
//p操作
int mysem_p(int semid)
{
    struct sembuf sem_buf;
    sem_buf.sem_num = 0;
    sem_buf.sem_op = -1;
    sem_buf.sem_flg = SEM_UNDO;
    if(semop(semid,&sem_buf,1) == -1)
    {
        perror("mysem_p");
        exit(-1);
    }
    return 0;
}
//v操作
int mysem_v(int semid)
{
    struct sembuf sem_buf;
    sem_buf.sem_num = 0;
    sem_buf.sem_op = 1;
    sem_buf.sem_flg = SEM_UNDO;
    if(semop(semid,&sem_buf,1) == -1)
    {
        perror("mysem_v");
        exit(-1);
    }
    return 0;
}
//删除信号
int mysem_del(int semid)
{
    union semnun sem_union;
    if(semctl(semid,0,IPC_RMID,sem_union) == -1)
    {
        perror("mysem_del");
        exit(-1);
    }
}


int main()
{
    pid_t  pid;
    int sem_id;
    int key;
    int ret;

    key = ftok("/home/liuqi/Documents/system_programming/process_5/",'a');
    if(key == -1)
    {
        perror("ftok");
        exit(-1);
    }

    sem_id = semget(key,1,IPC_CREAT|IPC_EXCL|0664);
    if(sem_id == -1)
    {
        if(errno != EEXIST)
        {
            perror("semget");
            exit(-1);
        }
    }
    mysem_init(sem_id,);
    ret = fork();
    switch(ret)
    {
        case -1:
            perror("fork");
            exit(-1);
        case 0:

        default:

    }

}