#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
	FILE *fp = NULL;
	fp = fopen("/home/liuqi/Documents/system_programming/VisualGDB/Debug/time1.txt", "w");
	time_t t;
	t = time(NULL);
	fprintf(fp, "time:%ld\n", t);
	fprintf(fp, "ctime:%s", (ctime(&t)));

	while (1)
	{
		t = time(NULL);
		struct tm *local = localtime(&t);

		fprintf(fp, "localtime:%d-%d-%d-%d-%d-%d\n", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, \
			local->tm_hour, local->tm_min, local->tm_sec);
		sleep(1);
		fflush(fp);
	}
	fclose(fp);
	return 0;
}