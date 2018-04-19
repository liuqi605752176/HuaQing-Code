#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main()
{
	int fd;
	fd = open("/home/liuqi/Documents/system_programming/IO_2/open.txt"
					,O_CREAT|O_RDWR,0666);
	if (fd < 0)
	{
		printf("fail to open open.txt!\n");
		return -1;
	}
	printf("sucess!fd = %d\n",fd);

	close(fd);
	return 0;
}