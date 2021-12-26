/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:06:44 by ash               #+#    #+#             */
/*   Updated: 2021/12/26 13:42:34 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int		is_finish(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->data->philo_cnt && philo->data->must_eat_cnt != -1)
	{
		if (philo[i].eat_cnt < philo[i].data->must_eat_cnt)
			break;
		i++;
	}
	if (i == philo->data->philo_cnt)
		return (1);
	return (0);
}

int		monitor_thread(t_philo *philo)
{
	int i;
	long long now;

	while (1)
	{
		i = 0;
		while (i < philo->data->philo_cnt)
		{
			get_time(&now);
			if (now - philo[i].last_eat_time >= philo[i].data->die_t && philo[i].last_eat_time){
				// printf("=============%lld %d is died\n", now - philo->data->start_t, philo[i].philo_id);
				mu_print(philo, i, "is died");
				pthread_mutex_unlock(&(philo->data->mutex_exec));
				return (0);
			}
			i++;
		}
		if (is_finish(philo) == 1)
		{
			pthread_mutex_unlock(&(philo->data->mutex_exec));
				return (0);
		}
	}
	return (1);
}