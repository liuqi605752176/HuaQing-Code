//
// Created by liuqi on 18-4-12.
//

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{

    int sockfd,datafd;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
        perror("socket");
        return -1;
    }
    struct sockaddr_in serveraddr,clientaddr;


    memset(&serveraddr,0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(50000);
    serveraddr.sin_addr.s_addr = inet_addr("172.25.1.176");

    if(bind(sockfd,(const struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1)
    {
        perror("bind");
        return -1;
    }
    if(listen(sockfd,5) == -1)
    {
        perror("listen");
        return -1;
    }

    socklen_t len = sizeof(clientaddr);

    int maxfd = sockfd;
    int ret;
    int i;
    char buf[10];
    int n;

    fd_set currentfds,globalfds;

    while(1)
    {
        FD_ZERO(&currentfds);
        currentfds = globalfds;
        ret = select(maxfd+1,&currentfds,NULL,NULL,NULL);
        printf("ret = %d\n",ret);

        for(i = 3;i < maxfd+1;i++)
        {
            if(FD_ISSET(i,&currentfds))
            {
                if(i == sockfd)
                {
                    datafd = accept(i,(struct sockaddr *)&clientaddr,&len);
                    FD_SET(i,&globalfds);
                    if(datafd>maxfd)
                        maxfd = datafd ;
                }
                else
                {
                    memset(buf,0, sizeof(buf));
                    n = recv(i,buf,sizeof(buf),0);

                    if(n == -1)
                    {
                        perror("recv");
                    }
                    if(n == 0)
                    {
                        FD_CLR(i,&globalfds);
                        close(i);
                        if(i == maxfd)
                        {
                            while(--maxfd)
                            {
                                if(FD_ISSET(maxfd,&globalfds))
                                    break;
                            }
                        }
                        printf("%s,%d退出\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
                    }
                }
            }
        }

    }
    return 0;
}