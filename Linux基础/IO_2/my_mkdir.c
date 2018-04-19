//
// Created by liuqi on 4/1/18.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int ret;
    ret =mkdir("/home/liuqi/Documents/system_programming/IO_2/my_mkdir",0777);
    if(ret < 0)
    {
        printf("creat my_mkdir failure\n");
        return -1;
    }
    else
    {
        printf("creat my_mkdir sucess!\n");
        printf("ret = %d\n",ret);
    }
}