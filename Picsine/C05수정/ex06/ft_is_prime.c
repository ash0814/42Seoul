int ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return 0;

	while (i < nb - 1)
	{
		if (nb % i == 0)
			return 0;
		i++;
	}
	return 1;
}

#include <stdio.h>
int main(void)
{
	int n = ft_is_prime(4219);
	printf("%d", n);
	return 0;
}
