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

int ft_find_next_prime(int nb)
{
	while (1)
	{
		if (ft_is_prime(nb) == 1)
			return nb;
		else
			nb++;
	}
	return 0;
}
#include <stdio.h>
int main(void)
{
	int n = ft_find_next_prime(214847);
	printf("%d", n);
	return 0;
}
