#include "header.h"

int is_printable(char str)
{
	if (str < 32 || str == 127)
		return (-1);
	return (0);
}

void ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		++i;
	}
}
