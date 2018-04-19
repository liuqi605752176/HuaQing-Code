#include <stdio.h>



int main(int argc, char const *argv[])
{
	int i, j, k, n;
	printf("水仙花数有：\n");
	for (n = 100; n < 1000; n++)
	{
		i = n / 100; //百位
		j = n / 10 % 10; //十位
		k = n % 10; //个位
		if (i * i * i + j * j * j + k * k * k == n)
		{
			printf("%3d\n", n);
		}
	}
	return 0;
}