#include <stdio.h>


int main(int argc, char const *argv[])
{

	char buf[5];
	fgets(buf, sizeof(buf), stdin);

	fputs(buf, stdout);
	return 0;
}