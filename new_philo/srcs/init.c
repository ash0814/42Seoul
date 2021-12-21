/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:33:16 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/22 01:53:02 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int		init_philo(t_philo *philo, char **argv, t_data *data)
{
	int	i;

	i = 0;
	philo->data = data;
	while (i < data->philo_cnt)
	{
		philo[i].data = data;
		philo[i].eat_cnt = 0;
		philo[i].last_eat_time = 0;
		philo[i].i = i;
		philo[i].philo_id = i + 1;
		philo[i].right = i;
		philo[i].left = (i + 1) % data->philo_cnt;
		i++;
	}
	// printf("a = %p\n", philo[0].data->fork[0]);
	// printf("b = %p\n", philo[0].data->fork[0]);
	// printf("c = %p\n", philo[0].data->fork[0]);
	// printf("d = %p\n", philo[0].data->fork[0]);
	return (0);
}

int		init_data(t_data *data, char **argv)
{
	int	i;

	data->philo_cnt = ft_atoi(argv[1]);
	data->die_t = ft_atoi(argv[2]);
	data->eat_t = ft_atoi(argv[3]);
	data->sleep_t = ft_atoi(argv[4]);
	get_time(&data->start_t);
	if (!argv[5])
		data->must_eat_cnt = -1;
	else
		data->must_eat_cnt = ft_atoi(argv[5]);
	if (mutex_init(&(data->fork), data->philo_cnt))
		return (err_int("mutex init error\n"));
	// printf("printf %d\n", data->fork[0]);
	// printf("printf %d\n", data->fork[0]);
	// printf("printf %d\n", data->fork);
	// printf("printf %d\n", data->fork);
	if (data->philo_cnt < 0 || data->die_t < 0 || data->eat_t < 0
			|| data->sleep_t < 0 || data->philo_cnt > 200)
		return (err_int("Input Error\n"));
	return (0);
}

int		init(t_data *data, t_philo *philo, char **argv)
{
	pthread_mutex_init(&data->mutex_print, NULL);
	pthread_mutex_init(&data->mutex_exec, NULL);
	pthread_mutex_lock(&data->mutex_exec);
	if (init_data(data, argv) || init_philo(philo, argv, data))
		return (1);
	return (0);
}
