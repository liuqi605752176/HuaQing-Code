#include <stdio.h>
#include <math.h>


int main(int argc, char const *argv[])
{
	int a, b, num1, num2, temp;
	printf("please input two numbers:\n");
	scanf("%d %d", &num1, &num2);
	if (num1 > num2)
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	a = num1; b = num2;
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	printf("最大公约数：%d\n", a);
	printf("最小公倍数：%d\n", num1 * num2 / a);

	return 0;
}