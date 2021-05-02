/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:05:46 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/24 19:55:17 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_char(int a, int fd)
{
	char c;

	c = a + '0';
	write(fd, &c, 1);
}

void	ft_print(int nb, int fd)
{
	if (nb > 9)
	{
		ft_print(nb / 10, fd);
		ft_print_char(nb % 10, fd);
	}
	else
		ft_print_char(nb, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_print(-n, fd);
	}
	else
		ft_print(n, fd);
}
