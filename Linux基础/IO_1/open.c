//
// Created by liuqi on 3/31/18.
//

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
    int fd;
    char buf[] = "hello linux";
    int wr_ret;
    int rd_ret;
    char rd_buf[128]={0};
    //fd = open(argv[1],O_CREAT|O_RDWR,0777);
    //fd = open("/home/liuqi/Documents/system_programming/IO_1/a.c",O_CREAT|O_EXCL|O_RDWR,0777);
    fd = open("/home/liuqi/Documents/system_programming/IO_1/a.c",O_RDWR|O_TRUNC);

    if (fd < 0)
    {
        printf("open file a.c failure,fd = %d\n",fd);
    }
    else
    {
        printf("open file a.c sucess,fd = %d\n",fd);
    }
    //写
    wr_ret = write(fd,buf, sizeof(buf));
    printf("wr_ret = %d\n",wr_ret);
    //读
    lseek(fd,0,SEEK_SET);
    lseek(fd,2,SEEK_SET);
    lseek(fd,1,SEEK_CUR);
    lseek(fd,-7,SEEK_END);
    rd_ret = read(fd,rd_buf,wr_ret);
    printf("rd_buf = %s\n",rd_buf);
    printf("rd_ret = %d\n",rd_ret);
    close(fd);
    return 0;
}