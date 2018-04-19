#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int a, num, i;
	long int sum = 0;
	//printf("请输入要相加的个数：\n");
	scanf("%d%d", &a, &num);
	printf("a = %d,num = %d\n", a, num);

	for (i = 0; i < num; i++)
	{
		for (j = )
			sum += a * pow(10, i);
	}
	printf("sum = a+aa+aaa+aaaa+... = %d\n", sum);


	return 0;
}