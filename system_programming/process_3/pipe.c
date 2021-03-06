//
// Created by liuqi on 4/3/18.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


void read_data(int pipes[]);

void write_data(int pipes[2]);

int main()
{
    int pipes[2],rc;
    pid_t pid;

    rc = pipe(pipes);
    if(rc == -1)
    {
        perror("pipes");
        exit(1);
    }
    pid =fork();
    switch(pid)
    {
        case -1:
            perror("fork fail");
            exit(1);
        case 0:
            printf("我是子进程！\n");
            //sleep(1);
            read_data(pipes);

        default:
            printf("我是父进程！\n");
            write_data(pipes);
    }
    return 0;
}

void read_data(int pipes[2])
{
    int c,rc;

    close(pipes[1]);
    while((rc = read(pipes[0],&c,1)) > 0)
    {
        putchar(c);
    }
    exit(0);
}

void write_data(int pipes[2])
{
    int c,rc;

    close(pipes[0]);
    while((c = getchar()) > 0)
    {
        rc = write(pipes[1],&c,1);
        if(rc == -1)
        {
            perror("parent:write");
            close(pipes[1]);
            exit(1);
        }
    }

    close(pipes[1]);
    exit(0);
}

