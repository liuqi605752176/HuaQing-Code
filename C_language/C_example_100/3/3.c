#include <stdio.h>
#include <math.h>

/**
 * @Author   liuqi
 * @DateTime 2018-03-16
 * @function 一个整数加上100后是一个完全平方数，再加168又是完全平方数
 * @return   0
 */

int main(int argc, char const *argv[])
{
	long  i, temp1, temp2;
	//long int x, y;
	for (i = 0; i < 100000; i++)
	{
		temp1 = sqrtf(i + 100);
		temp2 = sqrtf(i + 268);
		if ((temp1 * temp1 == i + 100) && (temp2 * temp2 == i + 268))
		{
			printf("-------->%ld\n", i);
		}

	}
	return 0;
}

