//
// Created by liuqi on 18-4-13.
//
#include "my_dict.h"
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


void do_register(int sockfd, MSG msg);

int do_login(int sockfd, MSG msg);

void do_query(int sockfd, MSG msg);

void do_history(int sockfd, MSG msg);

int main()
{
    int sockfd;

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
        perror("socket");
        return -1;
    }

    struct sockaddr_in clientaddr,serveraddr;

    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = inet_addr(IP);

    connect(sockfd,(const struct sockaddr *)&serveraddr, sizeof(serveraddr));

    MSG msg;

    while(1)
    {
        printf("**************************************************\n");
        printf("*********************1.register*******************\n");
        printf("*********************2.login**********************\n");
        printf("*********************3.quit***********************\n");
        printf("**************************************************\n");
        printf("please choose:");

        scanf("%d",&msg.type);

        switch(msg.type)
        {
            case REGISTER:
            {
                printf("\n");
                do_register(sockfd,msg);
                printf("\n");
                break;
            }
            case LOGIN: {
                printf("\n");
                if (do_login(sockfd, msg) == 1)
                {
                    printf("\n");
                    while (1)
                    {
                        printf("*****************************************\n");
                        printf("***************1.query_word**************\n");
                        printf("***************2.history_record**********\n");
                        printf("***************3.quit********************\n");
                        printf("please choose:");
                        scanf("%d",&msg.type);
                        if(msg.type == 1)
                            msg.type = QUERY_WORD;
                        else if(msg.type == 2)
                            msg.type = HISTORY_RECORD;

                        switch (msg.type) {
                            case QUERY_WORD:
                                printf("\n");
                                do_query(sockfd, msg);
                                printf("\n");
                                break;
                            case HISTORY_RECORD:
                                printf("\n");
                                do_history(sockfd, msg);
                                printf("\n");
                                break;
                            case QUIT:
                                close(sockfd);
                                exit(0);
                        }
                    }


                }
                break;
            }
            case QUIT:
            {
                close(sockfd);
                return 0;
            }
        }
    }


    return 0;
}

void do_history(int sockfd, MSG msg)
{
    //这里只定义了一个256大小的数组来存放数据库中的记录，如果记录过大，会
    //出现数组溢出需要更换
    char buf_record[256];

    msg.type = HISTORY_RECORD;
    send(sockfd,&msg, sizeof(msg),0);
    recv(sockfd,buf_record, sizeof(buf_record),0);
    printf("%s\n",buf_record);
}

void do_query(int sockfd, MSG msg)
{
    msg.type = QUERY_WORD;
    char buf_ans[256];
    while(1)
    {
        printf("请输入需要查询的单词：");
        scanf("%s",msg.data);
        send(sockfd,&msg,sizeof(msg),0);
        recv(sockfd,buf_ans, sizeof(buf_ans),0);
        printf("\n");
        printf("%s\n",buf_ans);
        if(msg.data == "#")
            break;
    }

}

int do_login(int sockfd, MSG msg)
{
    char buf_ans[128];

    msg.type = LOGIN;
    printf("请输入用户名：");
    scanf("%s",msg.name);
    printf("请输入密码：");
    scanf("%s",msg.data);

    send(sockfd,&msg, sizeof(msg),0);
    recv(sockfd,&buf_ans[128], sizeof(buf_ans),0);
    printf("%s",buf_ans);
    printf("\n");
    return 1;
}

void do_register(int sockfd, MSG msg)
{
    char buf[128]={0};

    msg.type = REGISTER;
    printf("请输入您所需要注册的用户名：");
    scanf("%s",msg.name);
    printf("请输入注册的密码：");
    scanf("%s",msg.data);

    send(sockfd, &msg, sizeof(msg),0);
    recv(sockfd,buf, sizeof(buf),0);
    printf("%s\n",buf);
}
