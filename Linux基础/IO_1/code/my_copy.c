#include <stdio.h>


int main(int argc, char const *argv[])
{
	if (argc < 3)
	{
		fprintf(stderr, "fail to open!\n");
		return -1;
	}

	FILE *fp = NULL;
	FILE *fb = NULL;
	int ch = 0;

	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stderr, "fail to fopen argv[1]!\n");
		return -1;
	}
	fb = fopen(argv[2], "w");
	if (fp == NULL)
	{
		fprintf(stderr, "fail to fopen argv[2]!\n");
		return -1;
	}

	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)
		{
			break;
		}
		else
		{
			fprintf(stderr, "fail\n");
		}

		fputc(ch, fb);
	}
	fclose(fp);
	fclose(fb);
	return 0;
}