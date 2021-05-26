/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 02:24:22 by sehyan            #+#    #+#             */
/*   Updated: 2020/11/30 04:06:07 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	cal(int a)
{
	int		k;
	int		j;
	char	t;
	char	o;

	k = a % 16;
	j = a / 16;
	if (k < 10)
		t = k + '0';
	else
		t = k - 10 + 'a';
	if (j < 10)
		o = j + '0';
	else
		o = j - 10 + 'a';
	write(1, "\\", 1);
	write(1, &o, 1);
	write(1, &t, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 127)
			cal(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int main()
{
	ft_putstr_non_printable("dd\n\\");
	return 0;
}
