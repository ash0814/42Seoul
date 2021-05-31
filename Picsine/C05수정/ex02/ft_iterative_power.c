int ft_iterative_power(int nb, int power)
{
	int count;
	int result;

	count = 0;
	result = 1;
	if (power < 0)
		return 0;
	while (count != power)
	{
		result *= nb;
		count++;
	}
	return result;
}
