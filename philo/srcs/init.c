/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:44:29 by ash               #+#    #+#             */
/*   Updated: 2021/11/30 20:40:43 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int init_mutex(pthread_mutex_t **mutex, int num)
{
	int i;

	*mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (!*mutex)
		return (1);
	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&(*mutex)[i], NULL);
		i++;
	}
	return (0);
}

int init_philo(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->data->p_cnt)
	{
		philo[i].data = philo->data;
		philo[i].eat_count = 0;
		philo[i].last_eat_time = 0;
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
	return (1);
}

void free_data(t_data *data, t_philo *philo)
{
	free(philo);
	free(data);
}

