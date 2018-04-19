//
// Created by liuqi on 18-4-12.
//


#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <zconf.h>

int main()
{
    int sockfd;

    sockfd = socket(AF_INET,SOCK_DGRAM,0);

    struct sockaddr_in serveraddr,clientaddr;

    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(50000);
    serveraddr.sin_addr.s_addr = inet_addr("172.25.1.176");

    bind(sockfd,(const struct sockaddr *)&serveraddr, sizeof(serveraddr));

    int maxfd = sockfd;
    fd_set readfds;

    int ret;
    int i;
    char buf[10];
    char buff[10];
    int n;
    FD_ZERO(&readfds);

    socklen_t len = sizeof(clientaddr);

    while(1)
    {
        FD_SET(sockfd,&readfds);
        FD_SET(0,&readfds);

        ret = select(maxfd+1,&readfds,NULL,NULL,NULL);
        printf("ret = %d\n",ret);
        for(i = 3;i <= maxfd;i++)
        {
            if(FD_ISSET(i,&readfds))
            {
                if(i == 0)
                {
                    memset(buf,0,sizeof(buf));
                    read(i,buf, sizeof(buf));
                    printf("stdin:%s\n",buf);
                }
                if(i == sockfd)
                {
                    memset(buff,0,sizeof(buf));
                    n = recvfrom(i,buff,sizeof(buff),0,(struct sockaddr *)&clientaddr,&len);
                    printf("ip:%s,port:%d,buff:%s\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port),buff);
                }
            }
        }
    }
    return 0;
}