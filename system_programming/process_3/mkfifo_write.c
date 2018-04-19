//
// Created by liuqi on 4/3/18.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
    int fd;
    int nwrite;
    if(argc < 2)
    {
        printf("argc error!\n");
        exit(-1);
    }
    if((fd = open("./myfifo",O_WRONLY)) < 0)
    {
        perror("fail to open myfifo:");
        exit(-1);
    }
    if((nwrite = write(fd,argv[1],strlen(argv[1])+1)) >0)
    {
        printf("Write %s to FIFO\n",argv[1]);
    }
    close(fd);
    return 0;

}