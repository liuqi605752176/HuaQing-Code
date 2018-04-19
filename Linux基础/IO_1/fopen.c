//
// Created by liuqi on 4/1/18.
//
#include <stdio.h>

int main()
{
    FILE *fp;
    char buf[] = "hello linux!";
    char wr_buf[128];
    fp = fopen("/home/liuqi/Documents/system_programming/IO_1/b.c","a");
    if(fp == NULL)
    {
        printf("open b.c fail!\n");
        return -1;
    }
    else
    {
        printf("open b.c sucess!\n");
    }

    fputs(buf,fp);

    //fflush(fp);
    //while(1);
    fgets(wr_buf,128,fp);
    printf("wr_buf = %s\n",wr_buf);*/

    fclose(fp);
    return 0;
}