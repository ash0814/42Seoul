#include <unistd.h>

int		main(int argc, char **argv)
{
	char cu[4];
	char cd[4];
	char rl[4];
	char rr[4];

	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		cu[i] = argv[i+1][0];
		i++;
	}
	while(i < 8)
	{
		cd[i] = argv[i+1][0];
		i++;
	}
	while(i < 12)
	{
		rl[i] = argv[i+1][0];
		i++;
	}
	while(i < 16)
	{
		rr[i] = argv[i+1][0];
		i++;
	}

	char k[24][4];
	char a[4][4];
	j = 0;
	while (j < 4)
	{
		if (rl[j] == 4)
		{
			a[i][0]=1;
			a[i][1]=2;
			a[i][2]=3;
			a[i][3]=4;
			j++;
		}
		j = 0;
		if (rr[j] == 4)
		{
			a[i][0]=4;
		}

	return 0;
}
