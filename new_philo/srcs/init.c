/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:33:16 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/26 17:31:55 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	if (!philo)
		return (err_int("Malloc Error\n"));
	i = 0;
	while (i < data->philo_cnt)
	{
		philo[i].data = data;
		philo[i].eat_cnt = 0;
		philo[i].last_eat_time = get_time();
		philo[i].i = i;
		philo[i].philo_id = i + 1;
		philo[i].right = i;
		philo[i].left = (i + 1) % data->philo_cnt;
		i++;
	}
	return (0);
}

int	init_data(t_data *data, char **argv)
{
	if (!data)
		return (err_int("Malloc Error\n"));
	pthread_mutex_init(&data->mutex_print, NULL);
	pthread_mutex_init(&data->mutex_exec, NULL);
	pthread_mutex_lock(&data->mutex_exec);
	data->philo_cnt = ft_atoi(argv[1]);
	data->die_t = ft_atoi(argv[2]);
	data->eat_t = ft_atoi(argv[3]);
	data->sleep_t = ft_atoi(argv[4]);
	data->start_t = get_time();
	if (!argv[5])
		data->must_eat_cnt = -1;
	else
		data->must_eat_cnt = ft_atoi(argv[5]);
	if (mutex_init(&(data->fork), data->philo_cnt))
		return (err_int("Mutex init error\n"));
	if (data->philo_cnt < 0 || data->die_t < 0 || data->eat_t < 0
		|| data->sleep_t < 0 || data->philo_cnt > 200)
		return (err_int("Input Error\n"));
	return (0);
}
