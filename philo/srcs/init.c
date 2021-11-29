/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:44:29 by ash               #+#    #+#             */
/*   Updated: 2021/11/29 20:46:38 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int init_philo(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->data->p_cnt)
	{
		philo[i].eat_count = 0;
		philo[i].last_eat_time = 0;
		philo[i].lfork_idx = i;
		if (i == 0)
			philo[i].rfork_idx = philo->data->p_cnt - 1;
		else
			philo[i].rfork_idx = i - 1;
		i++;
	}
	return (1);
}

int init_fork(t_fork *fork)
{
	int i;

	i = 0;
	while (i < fork->data->p_cnt)
	{
		fork[i].fid = i;
		fork[i].get_fork = 0;
		i++;
	}
	return (1);
}

int init_data(int argc, char **argv, t_data *data)
{
	if (argc == 5 || argc == 6)
	{
		data->p_cnt = ft_atoi(argv[1]);
		data->die_t = ft_atoi(argv[2]);
		data->eat_t = ft_atoi(argv[3]);
		data->sleep_t = ft_atoi(argv[4]);
		// data->start_t = gettime();
		if (argc == 6)
			data->must_eat_cnt = ft_atoi(argv[5]);
		else
			data->must_eat_cnt = -1;
		if (data->p_cnt < 0 || data->die_t < 0 || data->eat_t < 0 || 
			data->sleep_t < 0)
		{
			printf("input ERROR\n");
			return (0);
		}
	}
	else
	{
		printf("input ERROR\n");
		return (0);
	}
	
	// if (data->philo == NULL || data->fork == NULL)
	// 	return (0);
	// init_philo(data);
	// init_fork(data);
	return (1);
}

void free_data(t_data *data, t_philo *philo, t_fork *fork)
{
	free(philo);
	free(fork);
	free(data);
}

int			ft_atoi(const char *str)
{
	int m;
	int result;
	int i;

	m = 1;
	result = 0;
	i = 0;
	// while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
	// 	str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
	// 	i++;
	if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!('0' <= str[i] && str[i] <= '9' && str[i] != '\0'))
		return (-1);
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * m);
}
