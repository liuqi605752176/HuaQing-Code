//
// Created by liuqi on 4/2/18.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    pid_t  pid;
    time_t t;
    pid = fork();
    if(pid < 0)
    {
        perror("fork error!");
        exit(1);
    }
    else if(pid == 0)
    {
        if(setsid() == -1)
        {
            perror("setsid error!");
            exit(1);
        }
        if(chdir("/home/liuqi/Documents/system_programming/process_2/") == -1)
        {
            perror("chdir error!");
            exit(1);
        }
        umask(0);
        int num,i;
        num = getdtablesize();
        for(i = 0;i < num;i++)
        {
            close(i);
        }
        while(1)
        {
            FILE *fp;
            fp = fopen("/home/liuqi/Documents/system_programming/process_2/1.txt","w+");
            if(fp == NULL)
            {
                perror("creat 1.txt fail!");
                exit(1);
            }
            t = time(NULL);
            fprintf(fp,"ctime:%s",ctime(&t));
            fflush(fp);
            sleep(1);
        }
    }
    else
    {
        exit(0);
    }
}