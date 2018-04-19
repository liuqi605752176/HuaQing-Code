#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i, wages1 , wages2, wages4, wages6, wages10;
	float wages;

	printf("请输入当月利润(单位：万元)：\n");
	scanf("%d", &i);

	wages1 = i * 0.1;		//低于10万元部分的奖金
	wages2 = 10 * 0.1 + (i - 10) * 0.075;	//10-20万的奖金
	wages4 = wages2 + (i - 20) * 0.05;	//20-40万的奖金
	wages6 = wages4 + (i - 40) * 0.03;	//40-60万的奖金
	wages10 = wages6 + (i - 60) * 0.015;//60-100万的奖金


	if (i <= 10)
	{
		wages =  wages1;
	}
	else if (i > 10 && i <= 20)
	{
		wages =  wages2;
	}
	else if (i > 20 && i <= 40)
	{
		wages = wages4;
	}
	else if (i > 40 && i <= 60)
	{
		wages = wages6;
	}
	else if (i > 60 && i <= 100)
	{
		wages =  wages10;
	}
	else
	{
		wages =  wages10 + (i - 100) * 0.01;
	}

	printf("%6f\n", wages);
	return 0;
}


