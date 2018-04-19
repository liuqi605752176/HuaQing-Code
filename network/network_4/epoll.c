//
// Created by liuqi on 18-4-12.
//

#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <unistd.h>

int main()
{
    int sockfd,condfd;
    sockfd =socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
        perror("socket");
        return -1;
    }

    struct sockaddr_in serveraddr,clientaddr;
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(50000);
    serveraddr.sin_addr.s_addr = inet_addr("172.25.1.176");

   if(bind(sockfd,(const struct sockaddr *)&serveraddr, (socklen_t)sizeof(serveraddr)) == -1)
    {
        perror("bind");
        return -1;
    }
    if(listen(sockfd,5) == -1)
    {
        perror("listen");
        return -1;
    }

    int epfd;
    epfd = epoll_create(100);

    struct epoll_event ev;

    //确认监控的事件是读事件
    ev.events = EPOLLIN;
    //将需要监控的文件描述符加进结构体
    ev.data.fd = sockfd;
    //epoll的事件注册函数，它不同与select()是在监听事件时告诉内核要监听什么类型的事件，
    //而是在这里先注册要监听的事件类型。
    //第一个参数是epoll_create()的返回值，第二个参数表示动作，用三个宏来表示：
    //EPOLL_CTL_ADD：注册新的fd到epfd中；
    //EPOLL_CTL_MOD：修改已经注册的fd的监听事件；
    //EPOLL_CTL_DEL：从epfd中删除一个fd；
    //第三个参数是需要监听的fd，第四个参数是告诉内核需要监听什么事
    //注册新的fd到epfd中,进行监视
    epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&ev);

    socklen_t len = sizeof(clientaddr);
    struct epoll_event readyev[100];

    int ret;
    int i;
    char buf[10];
    int n;
    while(1)
    {
        ret = epoll_wait(epfd,readyev,100,-1);
        printf("ret = %d\n",ret);

        for(i = 0;i < ret;i++)
        {
            //当就绪的事件中的fd == sockfd时，说明该客户端要发送数据
            if(readyev[i].data.fd == sockfd)
            {
                //产生新的套接字进行数据传输
                condfd = accept(sockfd,(struct sockaddr *)&clientaddr,&len);
                //表示对应的文件描述符是可读的
                ev.events = EPOLLIN;
                ev.data.fd = condfd;
                //将新的套接字传给红黑树
                epoll_ctl(epfd,EPOLL_CTL_ADD,condfd,&ev);

            }
            else
            {
                //清空缓存数组
                memset(buf,0,sizeof(buf));
                //将处于就绪的客户端进行数据通讯
                n = recv(readyev[i].data.fd,buf,sizeof(buf),0);
                if(n == -1)
                {
                    perror("recv");
                }
                if(n == 0)
                {
                    //有客户端退出，删除这个节点的红黑树
                    epoll_ctl(epfd,EPOLL_CTL_DEL,readyev[i].data.fd,NULL);
                    //关闭文件描述符
                    close(readyev->data.fd);
                    printf("ip:%s port:%d 客户端退出",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
                }
                if(n > 0)
                {
                    printf("ip:%s,buf:%s\n",inet_ntoa(clientaddr.sin_addr),buf);
                }
            }
        }
    }
    return 0;
}