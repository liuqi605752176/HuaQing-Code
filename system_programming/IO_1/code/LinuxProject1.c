#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	extern int errno;
	int fd;
	fd = open("/home/liuqi/Documents/system_programming/IO_1/1.txt", O_CREAT | O_RDWR, 0777);
	fp = fopen("./hang.c", "r");

	if (fp == NULL)
	{
		fprintf(stderr, "file open fail:%s\n", strerror(errno));
	}
	printf("fd = %d", fd);

}