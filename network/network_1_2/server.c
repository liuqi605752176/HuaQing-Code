//
// Created by liuqi on 4/9/18.
//

#include <mynet.h>
#include <apeu.h>

typedef struct usrmsg
{
    char type;
    char name[15];
    char buf[128];
}usrmsg_t;

typedef struct node
{
    struct sockaddr_in data;
    struct node *next;
}linklist;

linklist *creat_empty_link()
{
    linklist *headnode = (linklist *)malloc(sizeof(linklist));
    if(headnode == NULL)
    {
        printf("创建控链表失败\n");
        return NULL;
    }

    headnode->next = NULL;
    return headnode;
}
void user_login(linklist *headnode,usrmsg_t usrmsg, struct sockaddr_in clientaddr,int sockfd)
{
    linklist *p = headnode->next;
    while(p != NULL)
    {
        sendto(sockfd, &usrmsg,sizeof(usrmsg),0,(const struct sockaddr *)&p->data, sizeof(p->data));
        p = p->next;
    }
    linklist*newnode = (linklist *)malloc(sizeof(linklist));

    newnode->data = clientaddr;

    newnode->next = headnode->next;
    headnode->next = newnode;

}
int main()
{
    int sockfd;
    usrmsg_t usrmsg;

    ssize_t  ret;

    char *ip = "172.25.1.176";
    struct sockaddr_in clientaddr,serveraddr;

    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd == -1)
    {
        perror("socket");
        exit(1);
    }
    memset(&serveraddr,0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(50000);
    serveraddr.sin_addr.s_addr = inet_addr(ip);

    bind(sockfd,(const struct sockaddr *)&serveraddr, sizeof(serveraddr));

    linklist *headnode;
    headnode = creat_empty_link();

    ssize_t len = sizeof(clientaddr);
    while(1)
    {
        ret = recvfrom(sockfd, &usrmsg, sizeof(usrmsg),0,(struct sockaddr *)&clientaddr, (socklen_t)&len);
        printf("ip:%s  ret:%d\n",inet_ntoa(clientaddr.sin_addr),ret);
        printf("type = %c name = %s\n",usrmsg.type,usrmsg.name);
        switch(usrmsg.type)
        {
            case 'L':
                user_login(headnode,usrmsg,clientaddr,sockfd);
                break;
            //case 'T':

        }
    }
    return 0;
}