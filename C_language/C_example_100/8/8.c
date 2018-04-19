#include <stdio.h>

/**
 * @Author   liuqi
 * @DateTime 2018-03-16
 * @function 九九乘法表
 * @param    argc       [description]
 * @param    argv       [description]
 * @return              [description]
 */
int main(int argc, char const *argv[])
{
	int i, j;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d ", i, j, i * j );
		}
		printf("\n");
	}
	return 0;
}