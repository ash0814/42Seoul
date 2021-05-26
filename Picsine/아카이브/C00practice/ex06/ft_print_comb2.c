/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:31:06 by sehyan            #+#    #+#             */
/*   Updated: 2020/11/24 12:27:44 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ex_while(int a);

void	print_char(int a, int b);

void	ft_print_comb2(void)
{
	int		front;
	int		back;

	front = 0;
	back = 0;
	while (front < 100)
	{
		back = front + 1;
		while (back < 100)
		{
			if (front < back)
			{
				print_char(front, back);
			}
			back++;
		}
		front++;
	}
}

void	print_char(int a, int b)
{
	char x;
	char y;

	x = (a / 10) + '0';
	y = (a % 10) + '0';
	write(1, &x, 1);
	write(1, &y, 1);
	write(1, " ", 1);
	x = (b / 10) + '0';
	y = (b % 10) + '0';
	if (a == 98 && b == 99)
	{
		write(1, &x, 1);
		write(1, &y, 1);
	}
	else
	{
		write(1, &x, 1);
		write(1, &y, 1);
		write(1, ", ", 2);
	}
}
