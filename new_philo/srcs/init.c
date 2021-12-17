/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:33:16 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/17 16:04:58 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int		init_philo(t_philo *philo, char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->p_cnt)
	{
		philo[i].data = data;
		philo[i].eat_cnt = 0;
		philo[i].last_eat_time = 0;
		philo[i].i = i;
		philo[i].philo_id = i + 1;
		philo[i].right = i;
		philo[i].left = (i + 1) % data->p_cnt;
	}
}

int		init_data(t_data *data, char **argv)
{
	pthread_mutex_init(data->mutex_print);
	pthread_mutex_init(data->mutex_exec);
	pthread_mutex_lock(data->mutex_exec);
	data->philo_cnt = ft_atoi(argv[1]);
	data->die_t = ft_atoi(argv[2]);
	data->eat_t = ft_atoi(argv[3]);
	data->sleep_t = ft_atoi(argv[4]);
	get_time(data->start_t);
	if (!(argc == 6 && data->must_eat_cnt = ft_atoi(argv[5])))
		data->must_eat_cnt = -1;
	if (data->philo_cnt < 0 || data->die_t < 0 || data->eat_t < 0
			|| data->sleep_t < 0 || data->philo_cnt > 200)
		return (err_int("Input Error\n"));
	return (0);
}

int		init(t_data *data, t_philo *philo, char **argv)
{
	data = (t_data *)malloc(sizeof(t_data));
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!data || !philo)
		return (1);
	if (init_data(data, argv) || init_philo(philo, argv, data))
		return (1);
}
