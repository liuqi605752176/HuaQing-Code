//
// Created by liuqi on 4/7/18.
//

#include <apeu.h>

struct msgbuf
{
    long type;
    char voltage[124];
    char ID[4];
};
int main()
{
    int msgid;
    int readret;
    struct  msgbuf sendbuf,rcvbuf;
    key_t key;
    key = ftok("/home/liuqi/Documents/system_programming/process_4/",'a');
    if(key == -1)
    {
        perror("ftok");
        exit(-1);
    }
    msgid = msgget(key,IPC_CREAT|0777);
    if(msgid < 0)
    {
        perror("msgget");
        exit(-1);
    }
    else
    {
        printf("创建消息队列成功，msgid = %d\n",msgid);
    }
    system("ipcs -q");

    sendbuf.type = 100;
    printf("请输入消息：\n");
    fgets(sendbuf.voltage,124,stdin);

    msgsnd(msgid,(void *)&sendbuf,strlen(sendbuf.voltage),0);


    bzero(rcvbuf.voltage,0);

    readret = msgrcv(msgid,(void *)&rcvbuf,124,100,0);
    printf("接收到的数据:%s",rcvbuf.voltage);
    printf("readret = %d\n",readret);




    msgctl(msgid,IPC_RMID,NULL);
    system("ipcs -q");
    return 0;
}