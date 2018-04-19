//
// Created by liuqi on 4/9/18.
//

#include <mynet.h>
#include <apeu.h>


int main()
{
    int socked;
    char buf[128];
    struct sockaddr_in clientaddr,serveraddr;

    socked = socket(AF_INET,SOCK_DGRAM,0);
    if(socked == -1)
    {
        perror("socket");
        exit(1);
    }
    memset(&serveraddr,0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = 50000;
    serveraddr.sin_addr.s_addr = inet_addr("172.25.1.176");

    bind(socked,(const struct sockaddr *)&serveraddr, sizeof(serveraddr));
    socklen_t len = sizeof(clientaddr);
    while(1)
    {
        memset(buf,0, sizeof(buf));
        recvfrom(socked,buf, sizeof(buf),0,(struct sockaddr *)&clientaddr, &len);
        printf("ip:%s,port:%d,data:%s\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port),buf);
    }
    return 0;
}