//
// Created by liuqi on 3/30/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{

    pid_t pid;
    int status;

    pid = fork();

    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
       while(1);
        exit(0);
    }
    else
    {
        //while(1);
        printf("父进程\n");
        printf("parent's pid = %d\n",getpid());
        printf("parent's ppid = %d\n",getppid());

        wait(&status);

        if(WIFEXITED(status))
        {
            printf("exit\n");
        }
        else if(WIFSIGNALED(status))
        {
            printf("signal\n");
        }

        int a =WEXITSTATUS(status);

        printf("%d\n",a);

        printf("%d\n",status);


        exit(0);
    }


    return 0;
}
