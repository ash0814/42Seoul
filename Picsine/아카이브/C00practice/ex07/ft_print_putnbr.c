/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:17:33 by sehyan            #+#    #+#             */
/*   Updated: 2020/11/24 21:26:44 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//함수 이름 잘못씀!
#include <unistd.h>

void	ft_print_char(int a)
{
	char c;

	c = a + '0';
	write(1, &c, 1);
}

void	ft_print(int nb)
{
	if (nb > 9)
	{
		ft_print(nb / 10);
		ft_print_char(nb % 10);
	}
	else
	{
		ft_print_char(nb);
	}
}

void	ft_print_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_print(-nb);
	}
	else
		ft_print(nb);
}
