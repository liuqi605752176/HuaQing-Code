#include <stdio.h>

void swap(int *x, int *y);

int main(int argc, char const *argv[])
{
	int a, b, c;
	printf("请输入３个整数：\n");
	scanf("%d%d%d", &a, &b, &c);
	if (a > b)
	{
		swap(&a, &b);
	}
	if (a > c)
	{
		swap(&a, &c);
	}
	if (b > c)
	{
		swap(&b, &c);
	}
	printf("三个数从小到大排序为：%d < %d < %d\n", a, b, c);
	return 0;
}
/**
 * @Author   liuqi
 * @DateTime 2018-03-16
 * @function　交换两个值
 * @param    *x
 * @param    *y
 */
void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
