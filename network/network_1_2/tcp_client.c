//
// Created by liuqi on 4/10/18.
//

#include <mynet.h>
#include <apeu.h>

int main()
{
    int sockfd;
    FILE *fp;

    fp = fopen("/home/liuqi/Documents/network/network_1_2/1.txt","r");
    
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
        perror("socket");
        return -1;
    }
    
    struct sockaddr_in clientaddr,serveraddr;

    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_addr.s_addr = inet_addr("172.25.1.176");
    serveraddr.sin_port = htons(50000);
    serveraddr.sin_family = AF_INET;

    if(connect(sockfd,(const struct sockaddr *)&serveraddr,(socklen_t)sizeof(serveraddr)) == -1)
    {
        perror("connect");
        return -1;
    }
    char buf[10];
    size_t n;

    while(1)
    {
        n = fread(buf,1,sizeof(buf),fp);
        send(sockfd,buf,n,0);
        if(n < sizeof(buf))
        {
            break;
        }
    }
    fclose(fp);
    close(sockfd);
    return 0;
}