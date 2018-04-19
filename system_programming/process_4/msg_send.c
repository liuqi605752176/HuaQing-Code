//
// Created by liuqi on 4/4/18.
//
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>
#include <errno.h>
#include <strings.h>
#include <string.h>


typedef struct msgbuf
{
    long mtype;
    char buf[128];
}MSG;

int main()
{
    key_t key;
    MSG msg;
    int msgid;
    int rval;
    key = ftok("/home/liuqi/Documents/system_programming/process_4/",'a');
    if(key == -1)
    {
        perror("key:");
        exit(-1);
    }
    msgid = msgget(key,IPC_CREAT | IPC_EXCL |0664);
    if(msgid == -1)
    {
        if(msgid == EEXIST)
        {
            perror("msgget:");
            exit(-1);
        }
        else
        {
            msgid = msgget(key,0664);
        }
    }
    msg.mtype = 100;
    while(1)
    {
        bzero(msg.buf,sizeof(msg.buf));
        fgets(msg.buf,sizeof(msg.buf),stdin);
        msg.buf[strlen(msg.buf) - 1] = '\0';
        rval = msgsnd(msgid,(void *)&msg,sizeof(msg.buf),0);
        if(rval == -1)
        {
            perror("msgsnd:");
            exit(-1);
        }


    }
    return 0;
}