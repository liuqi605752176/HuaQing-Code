//
// Created by liuqi on 4/9/18.
//


#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
typedef struct usrmsg
{
    char type;
    char name[15];
    char buf[128];

}usrmsg_t;


int main()
{
    pid_t pid;
    int sockfd;
    usrmsg_t usrmsg;
    struct sockaddr_in serveraddr;

    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd == -1)
    {
        perror("socket");
        exit(1);
    }
    memset(&serveraddr,0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(50000);
    serveraddr.sin_addr.s_addr = inet_addr("172.25.1.115");

    printf("请输入用户名：");
    fgets(usrmsg.name, sizeof(usrmsg.name),stdin);
    usrmsg.name[strlen(usrmsg.name) - 1] = '\0';
    usrmsg.type = 'L';
    sendto(sockfd, &usrmsg, sizeof(usrmsg), 0, (const struct sockaddr *) &serveraddr, sizeof(serveraddr));

    pid = fork();
    switch(pid)
    {
        case -1:
            perror("fork");
            exit(-1);
        case 0:
                
        default:
            while(1)
            {
                  recvfrom(sockfd,&usrmsg, sizeof(usrmsg),0,NULL,NULL);
                  switch(usrmsg.type)
                  {
                      case 'L':
                          printf("------------------%s login!-------------------\n",usrmsg.name);
                          break;
                  }
            }

            }


}



