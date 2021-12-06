/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:57:53 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/06 11:43:13 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	printf("%llums %d pickup right\n", get_time() - philo->data->start_t, philo->philo_num);
	pthread_mutex_lock(philo->lfork);
	printf("%llums %d pickup left\n", get_time() - philo->data->start_t, philo->philo_num);
	printf("%llums %d eating\n", get_time() - philo->data->start_t, philo->philo_num);
	philo->last_eat_time = get_time();
	usleep(philo->data->eat_t * 1000);
	// printf("%d last_eat_time : %llums\n", philo->philo_num, philo->last_eat_time - philo->data->start_t);
	philo->eat_count++;
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	sleeping(t_philo *philo)
{
	printf("%llums %d sleeping\n", get_time() - philo->data->start_t, philo->philo_num);
	usleep(philo->data->sleep_t * 1000);
}

void	thinking(t_philo *philo)
{
	printf("%llums %d thinking\n", get_time() - philo->data->start_t, philo->philo_num);
}

void	*f_philo(void *philo)
{
	t_philo *p;

	p = (t_philo *)philo;
	while (1)
	{
		eating(p);
		sleeping(p);
		thinking(p);
	}
	return (philo);
}

int	start_thread(t_philo *philo)
{
	int i;
	pthread_mutex_t *mutex;
	void *status;
	
	if (init_mutex(&mutex, philo->data->p_cnt))
		return (1);
	i = -1;
	while (++i < philo->data->p_cnt)
	{
		philo[i].philo_num = i + 1;
		if (i == 0)
			philo[i].rfork = &(mutex[philo->data->p_cnt - 1]);
		else
			philo[i].rfork = &(mutex[i - 1]);
		philo[i].lfork = &(mutex[i]);
		if (pthread_create(&(philo[i].tid), NULL, f_philo, &(philo[i])))
			return (1);
		pthread_detach(philo[i].tid);
	}
	return (0);
}