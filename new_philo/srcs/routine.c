/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:47:06 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/26 16:49:23 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	p_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_print);
	printf("%lld %d is sleeping\n",
		get_time() - philo->data->start_t, philo->philo_id);
	pthread_mutex_unlock(&(philo->data->mutex_print));
	s_sleep(philo, philo->data->sleep_t, get_time());
}

void	p_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_print);
	printf("%lld %d is thinking\n",
		get_time() - philo->data->start_t, philo->philo_id);
	pthread_mutex_unlock(&(philo->data->mutex_print));
}

void	pickup(pthread_mutex_t *fork, t_philo *philo)
{
	pthread_mutex_lock(fork);
	pthread_mutex_lock(&philo->data->mutex_print);
	printf("%lld %d has taken a fork\n",
		get_time() - philo->data->start_t, philo->philo_id);
	pthread_mutex_unlock(&(philo->data->mutex_print));
}

void	p_eat(t_philo *philo)
{
	if (philo->i % 2 == 0)
	{
		pickup(&(philo->data->fork[philo->right]), philo);
		pickup(&(philo->data->fork[philo->left]), philo);
	}
	else
	{
		pickup(&(philo->data->fork[philo->left]), philo);
		pickup(&(philo->data->fork[philo->right]), philo);
	}
	pthread_mutex_lock(&philo->data->mutex_print);
	printf("%lld %d is eating\n",
		get_time() - philo->data->start_t, philo->philo_id);
	pthread_mutex_unlock(&(philo->data->mutex_print));
	philo->eat_cnt++;
	philo->last_eat_time = get_time();
	s_sleep(philo, philo->data->eat_t, get_time());
	pthread_mutex_unlock(&(philo->data->fork[philo->right]));
	pthread_mutex_unlock(&(philo->data->fork[philo->left]));
}
