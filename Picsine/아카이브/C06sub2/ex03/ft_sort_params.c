/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:37:19 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/06 19:21:28 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_ar(int argc, char **argv)
{
	int i;
	int c;

	i = 0;
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
}

int		ft_strcmp(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] || b[i])
	{
		if (a[i] != b[i])
			break ;
		i++;
	}
	return (a[i] - b[i]);
}

void	ft_sort(int argc, char **argv)
{
	int		i;
	char	*t;

	i = 2;
	while (i < argc)
	{
		if (ft_strcmp(argv[i - 1], argv[i]) > 0)
		{
			t = argv[i];
			argv[i] = argv[i - 1];
			argv[i - 1] = t;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_sort(argc, argv);
		i++;
	}
	ft_print_ar(argc, argv);
	return (0);
}
