#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int i, j, flag = 0;

	for (i = 101; i <= 200; i++)
	{
		flag = 0;
		for (j = 1; j < ((int)sqrt(i)); j++)
		{
			if (i % j == 0)
			{
				flag++;
			}

		}
		if (flag == 1)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}

