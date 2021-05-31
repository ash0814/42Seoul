/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:02:42 by sehyan            #+#    #+#             */
/*   Updated: 2020/11/24 13:08:52 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char f, char s, char t);

void	ft_print_comb(void)
{
	char f;
	char s;
	char t;
	char c;

	f = '0';
	s = '0';
	t = '0';
	c = '9';
	while (f <= c)
	{
		s = '0';
		while (s <= c)
		{
			t = '0';
			while (t <= c)
			{
				print_char(f, s, t);
				t++;
			}
			s++;
		}
		f++;
	}
}

void	print_char(char f, char s, char t)
{
	if (f < s && s < t)
	{
		write(1, &f, 1);
		write(1, &s, 1);
		write(1, &t, 1);
		if (f < '7')
		{
			write(1, ",", 1);
			write(1, " ", 1);
		}
	}
}
