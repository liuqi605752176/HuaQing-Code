#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	extern int errno;
	char *fd;

	fp = fopen("./hang.c", "r");
	if (fp == NULL)
	{
		fd = strerror(errno);
		fprintf(stderr, "file open fail:%s\n", fd);
	}

	return 0;
}