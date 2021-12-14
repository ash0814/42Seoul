/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:35:53 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/14 16:07:58 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	s_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	s_nbr_char(int a, int fd)
{
	char c;

	c = a + '0';
	write(fd, &c, 1);
}

void	s_putnbr(int n)
{
	if (n > 9)
	{
		s_putnbr(n / 10);
		s_nbr_char(n % 10, 1);
	}
	else
		s_nbr_char(n, 1);
}