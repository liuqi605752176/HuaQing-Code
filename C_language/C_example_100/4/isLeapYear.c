#include <stdio.h>

/**
 * @Author   liuqi
 * @DateTime 2018-03-16
 * @function 计算年月日是这一年的第几天
 */
int main(int argc, char const *argv[])
{
	int year, month, day;
	int array[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i;
	int sum = 0;

	printf("请输入年月日（格式例如2018-3-8）：\n");
	scanf("%d-%d-%d", &year, &month, &day);

	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		array[1] = 29;
	}
	for (i = 0; i < month - 1; i++)
	{
		sum += array[i];
	}
	printf("%d-%d-%d是这一年的第%d天！\n", year, month, day, sum + day);
	return 0;
}