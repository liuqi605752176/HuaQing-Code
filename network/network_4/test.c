#include <stdio.h>
#include <sqlite3.h>
int main()
{
	sqlite3 *sq;
	sqlite3_open("./my.db",&sq);

}
