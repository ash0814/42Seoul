/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:26:31 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/06 15:30:23 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (++i < argc)
	{
		c = 0;
		while (argv[i][c] != '\0')
		{
			write(1, &argv[i][c], 1);
			c++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
