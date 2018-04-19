#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main()
{
	int size = 0;
	char *buf;

	FILE *fp1 = NULL;
	fp1 = fopen("/home/liuqi/Documents/system_programming/IO_1/code/my_copy.c", "r");
	if (fp1 == NULL)
	{
		fprintf(stderr, "fail to open my_copy.c\n");
		exit(-1);
	}
	FILE *fp2 = NULL;
	fp2 = fopen("/home/liuqi/Dcuments/system_programming/IO_1/code/fread_copy.txt\n","w+");
	if (fp2 == NULL)
	{
		fprintf(stderr, "fail to open fread_copy.txt\n");
		exit(-1);
	}
	fseek(fp1, 0, SEEK_END);
	size = ftell(fp1);
	rewind(fp1);
	long int count = 0;
	buf = (char *)malloc(sizeof(char)*size);
	count = fread(buf, sizeof(char), size, fp1);
	fwrite(buf, sizeof(buf), count, fp2);

	return 0;
}