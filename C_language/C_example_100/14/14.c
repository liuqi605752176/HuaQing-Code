#include <stdio.h>


int main(int argc, char const *argv[])
{
	int num, i;
	printf("请输入一个正整数：\n");
	scanf("%d", &num);
	printf("%d = ", num);

	for (i = 2; i <= (num / 2 + 1); i++)
	{
		if (num % i == 0)
		{
			printf("%d*", i);
			num = num / i;
		}
	}
	printf("%d", num);


	return 0;
}