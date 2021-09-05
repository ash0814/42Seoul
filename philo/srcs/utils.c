/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:44:29 by ash               #+#    #+#             */
/*   Updated: 2021/09/03 15:44:57 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int init_args(int argc, char **argv, t_args *args)
{
	if (argc == 5 || argc == 6)
	{
		args->philos = ft_atoi(argv[1]);
		args->die_t = ft_atoi(argv[2]);
		args->eat_t = ft_atoi(argv[3]);
		args->sleep_t = ft_atoi(argv[4]);
		if (argc == 6)
			args->must_t = ft_atoi(argv[5]);
		else
			args->must_t = -1;
		return (0);
	}
	return (1);
}

static int	i_atoi(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int m;
	int result;
	int i;

	m = 1;
	result = 0;
	i = i_atoi(str);
	if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * m);
}