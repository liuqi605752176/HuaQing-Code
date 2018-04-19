//
// Created by liuqi on 4/3/18.
//

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    int sig;
    if(argc < 3)
    {
        printf("please input param\n");
        return  -1;
    }
    
    kill((int)pid,sig);
}