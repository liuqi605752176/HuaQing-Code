#include <stdio.h>
#include <strings.h>


int main(int argc, const char *argv[])
{
	char buf[128];
	if (argc != 2 )
	{
		fprintf(stderr, "please input path!\n");
		return -1;
	}

	FILE *fp = NULL;
	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stderr, "fail to open path!\n");
		return -1;
	}


	while (1)
	{
		bzero(buf, sizeof(buf));
		if (fgets(buf, sizeof(buf), fp) == NULL)
		{

			if (feof(fp))
				break;
			else
			{
				fprintf(stderr, "fail to fgets\n");
				return -1;
			}
		}
		fputs(buf, stdout);
	}
}