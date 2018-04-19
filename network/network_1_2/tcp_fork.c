//
// Created by liuqi on 4/11/18.
//

#include <mynet.h>
#include <apeu.h>


int main()
{
    int sockfd,condfd;

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
        perror("socket");
        return -1;
    }

    struct sockaddr_in serveraddr,clientaddr;

    memset(&serveraddr,0, sizeof(serveraddr));
    serveraddr.sin_port = htons(50000);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("172.25.1.176");

    if(bind(sockfd,(const struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1)
    {
        perror("bind");
        return -1;
    }
    if(listen(sockfd,5) == -1){
        perror("listen");
        return -1;
    }

    socklen_t len = sizeof(clientaddr);

    pid_t pid;
    char buf[128];
    ssize_t reval;

    signal(SIGCHLD,SIG_IGN);
    while(1)
    {
        condfd = accept(sockfd,(struct sockaddr *)&clientaddr,&len);

        pid = fork();

        switch(pid)
        {
            case -1:
                perror("fork");
                return -1;
            case 0:
                close(sockfd);
                while(1)
                {
                    reval = recv(condfd,buf, sizeof(buf),0);
                    if(reval == -1)
                    {
                        perror("recv");
                        return -1;
                    }
                    if(reval == 0)
                    {
                        printf("ip:%s已退出客户端！\n",inet_ntoa(clientaddr.sin_addr));
                        return 0;
                    }
                    if(reval > 0)
                    {
                        printf("ip = %s,buf = %s\n",inet_ntoa(clientaddr.sin_addr),buf);
                    }
                }
            default:
            {
                close(condfd);
            }
        }
    }
    return 0;
}