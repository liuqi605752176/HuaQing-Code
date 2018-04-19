#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main()
{
	int fd1, fd2;
	int count = 0;
	char buf[128];
	fd1 = open("/home/liuqi/Documents/system_programming/IO_2/1.c", O_RDONLY);
	if (fd1 < 0)
	{
		printf("fail to open 1.c!\n");
		return -1;
	}
	printf("sucess!fd1 = %d\n", fd1);
	fd2 = open("/home/liuqi/Documents/system_programming/IO_2/open.txt",
	           O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd2 < 0)
	{
		printf("fail to open open.txt!\n");
		return -1;
	}
	printf("sucess!fd2 = %d\n", fd2);
	while (1)
	{
		count = read(fd1, buf, sizeof(buf) / sizeof(char));
		write(fd2, buf, count);

		//fseek(fd2,0,SEEK_END);
	}
	close(fd1);
	close(fd2);
	return 0;
}