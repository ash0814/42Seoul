int	ft_fibonacci(int index)
{
	if (index < 0)
		return -1;
	if (index == 0)
		return 0;
	else if (index == 1)
		return 1;
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

#include <stdio.h>
int main(void)
{
	int m = ft_fibonacci(-5);
	printf("%d", m);

	return 0;
}
