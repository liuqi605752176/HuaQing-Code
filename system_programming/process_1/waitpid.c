//
// Created by liuqi on 3/31/18.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int status;
    pid = fork();
    if(pid < 0)
    {
        perror("fork error!\n");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("this is child!\n");
        printf("child's pid = %d,ppid = %d\n",getpid(),getppid());
        while(1);
        exit(0);
    }
    else
    {
        printf("this is father!\n");
        printf("father's pid = %d,ppid = %d\n",getpid(),getppid());
        status = waitpid(-1,NULL,WNOHANG);
        if(-1 == status)
        {
            perror("wait");
            exit(1);
        }
        if(WIFEXITED(status))
            printf("正常退出！\n");
        else if(WIFSIGNALED(status))
            printf("信号退出!\n");
        exit(0);
    }

    return 0;
}

