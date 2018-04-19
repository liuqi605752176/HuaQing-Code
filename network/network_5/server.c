//
// Created by liuqi on 18-4-13.
//

#include "my_dict.h"
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <time.h>

//这里只定义了一个256大小的数组来存放数据库中的记录，如果记录过大，会
//出现数组溢出需要更换
char buf_record[256];


char *get_date();
int do_search_word(int condfd,MSG msg);

int register_by_callback(void *flag,int argc,char **argv,char **colname);
int record_by_callback(void *data,int argc,char **argv,char **colname);

void do_register(int condfd, MSG msg, sqlite3 *pSqlite3);

void do_login(int condfd, MSG msg, sqlite3 *pSqlite3);

void do_query(int condfd, MSG msg, sqlite3 *pSqlite3);

void do_history(int condfd, MSG msg, sqlite3 *pSqlite3);

int main()
{
    int sockfd,condfd;
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("./user.db",&db);
    if(rc)
    {
        fprintf(stderr,"can't open database:%s\n",sqlite3_errmsg(db));
        exit(0);
    }

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
        perror("socket");
        return -1;
    }

    struct sockaddr_in clientaddr,serveraddr;

    memset(&serveraddr,0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = inet_addr(IP);

    if((bind(sockfd,(const struct sockaddr *)&serveraddr, sizeof(serveraddr))) == -1)
    {
        perror("bind");
        return -1;
    }
    if((listen(sockfd,5)) == -1)
    {
        perror("listen");
        return -1;
    }

    signal(SIGCHLD,SIG_IGN);

    socklen_t len = sizeof(clientaddr);
    pid_t pid;
    ssize_t reval;
    MSG msg;

    while(1)
    {
        condfd = accept(sockfd,(struct sockaddr *)&clientaddr, &len);


        pid = fork();

        switch(pid)
        {
            case -1:
                perror("fork");
                break;
            case 0:
                close(sockfd);
                while(1)
                {
                    reval = recv(condfd,&msg, sizeof(msg),0);
                    if(reval == -1)
                    {
                        perror("recv");
                        break;
                    }
                    else if(reval == 0)
                    {
                        printf("ip:%s已退出客户端!\n",inet_ntoa(clientaddr.sin_addr));
                        break;
                    }
                    else if(reval > 0)
                    {
                        switch(msg.type)
                        {
                            case REGISTER:
                                do_register(condfd,msg,db);
                                break;
                            case LOGIN:
                                do_login(condfd,msg,db);
                                break;
                            case QUERY_WORD:
                                do_query(condfd,msg,db);
                                break;

                             case HISTORY_RECORD:
                                do_history(condfd,msg,db);
                                break;

                            default:
                                printf("ip = %s已退出！\n",inet_ntoa(clientaddr.sin_addr));
                                break;
                        }
                    }
                }

            default:
                exit(EXIT_SUCCESS);
        }
    }

}

char *get_date()
{
    time_t t;
    t = (unsigned)time(NULL);

    return ctime(&t);
}
int record_by_callback(void *data,int argc,char **argv,char **colname)
{
    int i;

    for(i = 0;i <argc;i++)
    {
        sprintf(buf_record,"单词：%s  上次查询时间：%s",colname[i],argv[i]);
    }
    printf("\n");
    return 0;
}

int do_search_word(int condfd,MSG msg)
{
    FILE *fp;
    char buf_word[128];
    char buf_ans[256];
    int result;
    char *p;
    fp = fopen("./dict.txt","r");
    if(fp == NULL)
    {
        send(condfd,"can't be opened dict.txt",128,0);
    }
    while(fgets(buf_word,256,fp) != NULL)
    {
        memset(buf_ans,0, sizeof(buf_ans));
        memset(buf_word,0, sizeof(buf_word));
        result = strncmp(msg.data,buf_word,strlen(msg.data));
        if(result > 0)
            continue;
        if(result < 0||buf_word[strlen(msg.data)] != ' ')
            break;
        p = buf_word;
        while(*p == ' ')
            p++;
        strcpy(buf_ans,p);
        send(condfd,buf_ans,sizeof(buf_ans),0);
        return 1;
    }
    return 0;
}
int register_by_callback(void *flag,int argc,char **argv,char **colname)
{
    int *p;
    *p = 0;
    flag = p;
    return 0;
}
void do_register(int condfd, MSG msg, sqlite3 *pSqlite3)
{
    int flag = 1;
    char optsql[128];
    char *errmsg;

    sprintf(optsql,"select * from usermsg where name = '%s'",msg.name);
    if(sqlite3_exec(pSqlite3,optsql,register_by_callback,&flag,&errmsg) != SQLITE_OK)
    {
        printf("%s\n",errmsg);
        send(condfd,errmsg, sizeof(errmsg),0);
        sqlite3_free(errmsg);
    }
    printf("flag = %d\n",flag);
    if(flag == 1)
    {
        sprintf(optsql, "insert into usermsg values('%s','%s')", msg.name, msg.data);
        if (sqlite3_exec(pSqlite3, optsql, NULL, NULL, &errmsg) != SQLITE_OK)
        {
            printf("%s\n", errmsg);
            send(condfd, errmsg, sizeof(errmsg), 0);
            sqlite3_free(errmsg);
        }

        char success[128] = "register success,please choose login or quit\n!";
        send(condfd, success, sizeof(success), 0);

        sqlite3_free(errmsg);

    }
}

void do_login(int condfd, MSG msg, sqlite3 *pSqlite3)
{
    //遍历数据库，匹配用户名密码
    char optsql[128];
    char *errmsg;
    sprintf(optsql,"select * from usermsg where name = '%s' AND data = '%s'",msg.name,msg.data);
    if(sqlite3_exec(pSqlite3,optsql,NULL,NULL,&errmsg) != SQLITE_OK)
    {
        send(condfd,errmsg, sizeof(errmsg),0);
        sqlite3_free(errmsg);
    }
    else
    {
        memset(msg.data,0, sizeof(msg.data));
        char success[128] = "login success!";
        send(condfd,success, sizeof(success),0);
        sqlite3_free(errmsg);
    }

}

void do_query(int condfd, MSG msg, sqlite3 *pSqlite3)
{
    int found;
    char optsql[128];
    char *errmsg;
    while(1)
    {
        found = do_search_word(condfd, msg);
        switch (found) {
            case 1:
                get_date();
                sprintf(optsql, "insert into history_record values('%s','%s')", msg.data, get_date());
                if (sqlite3_exec(pSqlite3, optsql, NULL, NULL, &errmsg) != SQLITE_OK) {
                    send(condfd, errmsg, sizeof(errmsg), 0);
                    sqlite3_free(errmsg);
                }
            case 0:
                send(condfd, "not found", 128, 0);
        }
    }

}

void do_history(int condfd, MSG msg, sqlite3 *pSqlite3)
{
    char optsql[128];
    char *errmsg;
    sprintf(optsql,"select * from history_record;");
    sqlite3_exec(pSqlite3,optsql,record_by_callback,NULL,&errmsg);
    send(condfd,buf_record,sizeof(buf_record),0);
}
