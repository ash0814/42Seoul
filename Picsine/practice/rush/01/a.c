#include <unistd.h>
#include <stdlib.h>

void put_arr(char **a);
void malloc_arr(char **a);

char g_cu[4];
char g_cd[4];
char g_rl[4];
char g_rr[4];

int main(int argc, char **argv)
{
	char **a;

	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		g_cu[i] = argv[i+1][0];
		i++;
	}
	while(i < 8)
	{
		g_cd[i-4] = argv[i+1][0];
		i++;
	}
	while(i < 12)
	{
		g_rl[i-8] = argv[i+1][0];
		i++;
	}
	while(i < 16)
	{
		g_rr[i-12] = argv[i+1][0];
		i++;
	}

	malloc_arr(a);
	put_arr(a);
	write(1, a[0], 7);
	return 0;
}

void malloc_arr(char **a)
{
	int i;

	i = 0;
	*a = (char*)malloc(sizeof(char *) * 24);
	while (i < 24)
	{
		a[i] = (char*)malloc(sizeof(char) * 7);
		i++;
	}
}

void put_arr(char **a)
{
	a[0] = "1 2 3 4";
	a[1] = "1 2 4 3";
	a[2] = "1 3 2 4";
	a[3] = "1 3 4 2";
	a[4] = "1 4 2 3";
	a[5] = "1 4 3 2";
	a[6] = "2 1 3 4";
	a[7] = "2 1 4 3";
	a[8] = "2 3 1 4";
	a[9] = "2 3 4 1";
	a[10] = "3 1 2 4";
	a[11] = "3 1 4 2";
	a[12] = "3 2 1 4";
	a[13] = "3 2 4 1";
	a[14] = "3 4 1 2";
	a[15] = "3 4 2 1";
	a[16] = "4 1 2 3";
	a[17] = "4 1 3 2";
	a[18] = "4 2 1 3";
	a[19] = "4 2 3 1";
	a[20] = "4 3 1 2";
	a[21] = "4 3 2 1";
	a[22] = "2 4 1 3";
	a[23] = "2 4 3 1";
}
