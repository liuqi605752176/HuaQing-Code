//
// Created by liuqi on 3/30/18.
//
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid,ppid;
    pid = getpid();
    ppid = getppid();
    printf("PID = %d\n",pid);
    printf("PPID = %d\n",ppid);
    return 0;
}
