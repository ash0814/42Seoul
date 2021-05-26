int ft_sqrt(int nb)
{
	long long int i;


	i = 1;
	if (nb == 1)
		return 1;
	while (i < nb / 2)
	{
		if (i * i == (long long)nb)
			return i;
		else
			i++;
	}
	return 0;
}
#include <stdio.h>
int main(void)
{
	int n = ft_sqrt(2147483647);
	printf("%d", n);
	return 0;
}
