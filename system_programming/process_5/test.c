#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	printf("hello1");
	pid = fork();
	if (pid == 0)
	{
		printf("hello2");
	}

	return 0;
}