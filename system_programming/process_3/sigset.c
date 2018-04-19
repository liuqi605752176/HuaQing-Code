//
// Created by liuqi on 4/3/18.
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler1()
{
    printf("hello linux!\n");
}
void handler2()
{
    printf("hello world!\n");
}

int main()
{

    //__sighandler_t sig;
    signal(SIGINT,handler1);
    signal(SIGTSTP,handler2);
    pause();
    printf("liuqi\n");
    while(1);

}