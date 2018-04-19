#include <stdio.h>


int main(int argc, char const *argv[])
{
	int i, j, k;
	int count = 0;
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 4; j++)
			for (k = 1; k <= 4; k++)
			{
				if ((i != j) && (i != k) && (j != k))
				{
					printf("%d\n", i * 100 + j * 10 + k);
					count++;
				}
			}


	printf("%d\n", count);
	return 0;
}
