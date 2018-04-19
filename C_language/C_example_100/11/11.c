#include <stdio.h>

int fun(int n);

int main(int argc, char const *argv[])
{
	int i;
	for (i = 1 ; i < 20; i++)
	{
		printf("%2d\n", fun(i));
	}

	return 0;
}

int fun(int n)
{
	if (n < 0)
	{
		return -1;
	}
	else if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return fun(n - 2) + fun(n - 1);
	}

}