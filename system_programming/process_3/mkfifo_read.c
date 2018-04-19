//
// Created by liuqi on 4/3/18.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
    int fd;
    char buf[128];
    int nread;
    if(access("./myfifo",F_OK) == -1)
    {
        if (mkfifo("./myfifo", 0666) < 0)
        {
            perror("fail to mkfifo:");
            exit(-1);
        }

    }
    if((fd = open("./myfifo",O_RDONLY)) < 0)
    {
        perror("fail to open myfifo:");
        exit(-1); 
    }
    while(1)
    { 
        bzero(buf,sizeof(buf));
        if(nread = read(fd,buf,sizeof(buf)) > 0)
        {
            printf("read %s from fifo\n"); 
        }
    }
        
    
    close(fd);
    return 0;
}