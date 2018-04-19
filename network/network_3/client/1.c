//
// Created by liuqi on 4/9/18.
//

#include <mynet.h>

int main()
{
    char *ip = "190.168.1.1";
    in_addr_t netaddr;

    netaddr = inet_addr(ip);
    printf("netaddr = %x\n",netaddr);

    struct in_addr in;
    in.s_addr = netaddr;

    ip = inet_ntoa(in);

    printf("ip = %s\n",ip);
    return 0;

}