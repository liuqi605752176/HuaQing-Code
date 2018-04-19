//
// Created by liuqi on 3/30/18.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
    pid_t pid,pid2;
    int status;
    printf("hello world!\n");
    pid = fork();
   // printf("liuqi!\n");
    if (pid < 0)
    {
        perror("fork!");
        return -1;
    }
    else if(pid == 0)
    {
        printf("子进程\n");
        printf("child's pid = %d\n",getpid());
        printf("child's ppid = %d\n",getppid());
        exit(0);

    }
    else
    {
        printf("父进程\n");
        printf("parent's pid = %d\n",getpid());
        printf("parent's ppid = %d\n",getppid());

        pid2 = wait(&status);
        printf("pid2 = %d\n",pid2);
        getchar();
        if(WIFEXITED(status))
        {
            printf("正常退出！\n");
        }
        else if(WIFSIGNALED(status))
        {
            printf("信号终结！\n");
        }
        int a = WEXITSTATUS(status);
        printf("a = %d\n",a);
        printf("status = %d\n",status);
        exit(0);
    }
    
}