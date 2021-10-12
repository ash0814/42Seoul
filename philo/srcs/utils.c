/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:44:29 by ash               #+#    #+#             */
/*   Updated: 2021/10/12 19:28:09 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int init_philo(t_philo *philo, int p_cnt)
{
	int i;

	i = 0;
	while (i < p_cnt)
	{
		philo[i].tid = 0;
		i++;
	}
}

int init_fork(t_fork *fork, int p_cnt)
{

}



int init_data(int argc, char **argv, t_data *data)
{
	if (argc == 5 || argc == 6)
	{
		data->p_cnt = ft_atoi(argv[1]);
		data->die_t = ft_atoi(argv[2]);
		data->eat_t = ft_atoi(argv[3]);
		data->sleep_t = ft_atoi(argv[4]);
		if (argc == 6)
			data->cnt_eat = ft_atoi(argv[5]);
		else
			data->cnt_eat = -1;
		return (0);
	}
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->p_cnt);
	data->fork = (t_fork *)malloc(sizeof(t_fork) * data->p_cnt);
	init_philo(data->philo, data->p_cnt);
	init_fork(data->fork, data->p_cnt);
	return (1);
}

int	i_atoi(const char *str)
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