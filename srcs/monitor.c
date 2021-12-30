/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:06:44 by ash               #+#    #+#             */
/*   Updated: 2021/12/26 19:51:31 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_finish(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_cnt && philo->data->must_eat_cnt != -1)
	{
		if (philo[i].eat_cnt < philo[i].data->must_eat_cnt)
			break ;
		i++;
	}
	if (i == philo->data->philo_cnt)
		return (1);
	return (0);
}

int	monitor_thread(t_philo *philo)
{
	int	i;

	while (true)
	{
		i = 0;
		usleep(50);
		while (i < philo->data->philo_cnt)
		{
			if (get_time() - philo[i].last_eat_time > philo[i].data->die_t)
			{
				pthread_mutex_lock(&philo->data->mutex_print);
				printf("%lld %d is died\n",
					get_time() - philo->data->start_t, philo->philo_id);
				return (0);
			}
			i++;
		}
		if (is_finish(philo) == 1)
			return (0);
	}
	return (1);
}
