
#include <unistd.h>

int main(int argc, char **argv)
{
	char arr[5][5];
	int i;

	i = 0;
	while (i < 5)
	{
		arr[1][i] = argv[1][i];
		write(1, &arr[1][i], 1);
		i++;
	}
	return 0;
}
