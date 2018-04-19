//
// Created by liuqi on 4/9/18.
//

#include <mynet.h>

int main()
{
    uint16_t norder,horder;   //定义网络字节序端口号和主机端口号

    horder = 0x1234;          //主机端口号初始化
    norder = htons(horder);   //将主机字节序转化为网络字节序
    printf("%#x\n",norder);

    horder = ntohs(norder);   //将网络字节序转化为主机字节序
    printf("%#x\n",horder);

    return 0;
}