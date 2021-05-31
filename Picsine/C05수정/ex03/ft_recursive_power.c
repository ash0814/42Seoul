int ft_recursive_power(int nb, int power)
{
	int count;
	int result;

	if (power == 0)
		return 1;
	else if (power < 0)
		return 0;
	count = 0;
	result = nb * ft_recursive_power(nb, power - 1);
	return result;
}

#include <stdio.h>
int main(void)
{
	int n = ft_recursive_power(-3, -3);
	printf("%d", n);
	return 0;
}
