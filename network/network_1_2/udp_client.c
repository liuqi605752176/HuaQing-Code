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
    memset(&clientaddr,0, sizeof(clientaddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = 50000;
    serveraddr.sin_addr.s_addr = inet_addr("172.25.1.176");

    while(1)
    {
        fgets(buf, sizeof(buf),stdin);
        sendto(socked,buf,strlen(buf),0,(const struct sockaddr *)&serveraddr, (socklen_t)sizeof(serveraddr));
        if(strncmp(buf,"quit",4) == 0)
            break;
    }
    close(socked);
}