#include <stdio.h>

int main(int argc, char const *argv[])
{
	int score = 0;
	char grade;
	printf("请输入分数：\n");
	scanf("%d", &score);

	grade = (score >= 90) ? 'A' : (score >= 60 ? 'B' : 'C');

	printf("%c", grade);
	return 0;
}