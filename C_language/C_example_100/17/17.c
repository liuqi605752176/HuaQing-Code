#include <stdio.h>

int main(int argc, char const *argv[])
{
	char c;
	int i, count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	printf("请输入一行字符：\n");

	while ((c = getchar()) != '\n')
	{
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
		{
			count1++;
		}
		else if (c == ' ')
		{
			count2++;
		}
		else if (c >= '0' && c <= '9')
		{
			count3++;
		}
		else
		{
			count4++;
		}

	}
	printf("英文字母个数：%d\n", count1);
	printf("空格个数：%d\n", count2);
	printf("数字个数：%d\n", count3);
	printf("其它字符个数：%d\n", count4);
	return 0;
}



