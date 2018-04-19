//
// Created by liuqi on 4/10/18.
//

#include <mynet.h>
#include <apeu.h>

int main()
{
    FILE *fp;
    fp = fopen("/home/liuqi/Documents/network/network_1_2/2.txt","w");
    int sockfd,acptfd;

    //创建套接字
    sockfd = socket(AF_INET,SOCK_STREAM,0);

    if(sockfd == -1)
    {
        perror("socket");
        return -1;
    }
    struct sockaddr_in clientaddr,serveraddr;

    //填充服务器地址结构体
    memset(&serveraddr,0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(50000);
    serveraddr.sin_addr.s_addr = inet_addr("172.25.1.176");

    //绑定服务器地址结构
    if(bind(sockfd,(const struct sockaddr *)&serveraddr, sizeof(serveraddr))== -1)
    {
        perror("bind");
        return -1;
    }

    //监听---为了和客户端建立连接做准备
    if(listen(sockfd,5) == -1)
    {
        perror("listen");
        return -1;
    }

    //产生新的文件描述符

    socklen_t len = sizeof(clientaddr);

    printf("1111\n");
       
    acptfd = accept(sockfd, (struct sockaddr *) &clientaddr, &len);

    printf("2222222\n");
    if (acptfd == -1)
    {
        perror("accept");
        return -1;
    }
    //循环接收客户端发送的数据‘
    ssize_t ret;
    char buf[10];

    while (1)
    {
        memset(buf,0, sizeof(buf));
        ret = recv(acptfd, buf, sizeof(buf), 0);
        if (ret == -1)
        {
            perror("recv");
            return -1;
        }
        if (ret == 0)
        {
            printf("有客户端退出！\n");
            break;
        }
        if (ret > 0)
        {
            fwrite(buf,1,(size_t)ret,fp);
            if(ret < sizeof(buf))
            {
                break;
            }
        }
    }


   fclose(fp);
   close(sockfd);
   close(acptfd);
    return  0;
}