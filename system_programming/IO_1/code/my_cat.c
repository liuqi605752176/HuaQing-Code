#include <stdio.h>



int main(int argc, const char *argv[])
{
	if (argc != 2 )
	{
		fprintf(stderr, "please input path!\n");
		return -1;
	}

	FILE *fp = NULL;
	fp = fopen(argv[1], "r");

	int ch = 0;
	if (fp == NULL)
	{
		fprintf(stderr, "fail to open path!\n");
		return -1;
	}
	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)
		{
			if (feof(fp))
			{
				break;
			}
			else
			{
				perror("fail!");
			}

		}
		fputc(ch, stdout);
	}


}
