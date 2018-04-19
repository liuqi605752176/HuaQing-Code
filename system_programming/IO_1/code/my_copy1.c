#include <stdio.h>
#include <strings.h>

int main(int argc, char const *argv[])
{
	if (argc < 3)
	{
		fprintf(stderr, "fail to open!\n");
		return -1;
	}

	FILE *fp = NULL;
	FILE *fb = NULL;
	char buf[128];

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
		bzero(buf, sizeof(buf));

		if (NULL == fgets(buf, sizeof(buf), fp))
		{
			if (feof(fp))
				break;
			else
			{
				fprintf(stderr, "fail to fgets\n");
				return -1;
			}
		}

		fputs(buf, fb);
	}
	fclose(fp);
	fclose(fb);
	return 0;
}