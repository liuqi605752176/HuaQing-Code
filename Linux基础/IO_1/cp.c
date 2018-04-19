//
// Created by liuqi on 4/1/18.
//
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>


int main(int argc,char *argv[])
{
    int rd_fd,wr_fd;
    int rd_ret;
    char rd_buf[128] = {0};

    if(argc < 3)
    {
        printf("請輸入指令、文件名和目標文件名！\n");
        return -1;
    }
    rd_fd = open(argv[1],O_RDONLY);
    if(rd_fd < 0)
    {
        perror("fail to open argv[1]!");
        return -2;
    }
    else
        printf("open %s sucess,rd_fd = %d\n",argv[1],rd_fd);
    wr_fd = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC);
    if(wr_fd < 0)
    {
        perror("fail to open argv[2]");
        return -3;
    }
    else
        printf("open %s sucess,wr_fd = %d\n",argv[2],wr_fd);
    while(1)
    {
        rd_ret = read(rd_fd, rd_buf, sizeof(rd_buf) / sizeof(char));
        if( rd_ret < 128)
            break;
        wr_fd = write(wr_fd, rd_buf, rd_ret);
        bzero(rd_buf,sizeof(rd_buf));

    }
    write(wr_fd,rd_buf,rd_ret);

    close(rd_fd);
    close(wr_fd);
    return 0;
}