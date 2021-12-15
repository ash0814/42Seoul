/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:57:53 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/15 17:10:50 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eating(t_philo *philo)
{
	if (philo->philo_num % 2 == 1)
	{
		pthread_mutex_lock(philo->lfork);
		pthread_mutex_lock(&(philo->data->m_print));
		printf("%llu %d has taken a fork\n",
			get_time() - philo->data->start_t, philo->philo_num);
		pthread_mutex_unlock(&(philo->data->m_print));
		pthread_mutex_lock(philo->rfork);
		pthread_mutex_lock(&(philo->data->m_print));
		printf("%llu %d has taken a fork\n",
			get_time() - philo->data->start_t, philo->philo_num);
		pthread_mutex_unlock(&(philo->data->m_print));
	}
	else
	{
		pthread_mutex_lock(philo->rfork);
		pthread_mutex_lock(&(philo->data->m_print));
		printf("%llu %d has taken a fork\n",
			get_time() - philo->data->start_t, philo->philo_num);
		pthread_mutex_unlock(&(philo->data->m_print));
		pthread_mutex_lock(philo->lfork);
		pthread_mutex_lock(&(philo->data->m_print));
		printf("%llu %d has taken a fork\n",
			get_time() - philo->data->start_t, philo->philo_num);
		pthread_mutex_unlock(&(philo->data->m_print));
	}
	pthread_mutex_lock(&(philo->data->m_print));
	printf("%llu %d is eating\n",
		get_time() - philo->data->start_t, philo->philo_num);
	pthread_mutex_unlock(&(philo->data->m_print));
	philo->last_eat_time = get_time();
	ssleep(philo->data->eat_t, get_time());
	philo->eat_count++;
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->m_print));
	printf("%llu %d is sleeping\n",
		get_time() - philo->data->start_t, philo->philo_num);
	pthread_mutex_unlock(&(philo->data->m_print));
	// usleep(philo->data->sleep_t * 1000);
	ssleep(philo->data->sleep_t, get_time());
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->m_print));
	printf("%llu %d is thinking\n",
		get_time() - philo->data->start_t, philo->philo_num);
	pthread_mutex_unlock(&(philo->data->m_print));
}

void	*f_philo(void *philo)
{
	t_philo	*p;

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
	int				i;
	pthread_mutex_t	*mutex;
	void			*status;

	if (init_mutex(&mutex, philo->data->p_cnt))
		return (1);
	i = -1;
	while (++i < philo->data->p_cnt)
	{
		philo[i].philo_num = i + 1;
		philo[i].rfork = &(mutex[i]);
		if (i + 1 == philo->data->p_cnt)
			philo[i].lfork = &(mutex[0]);
		else
			philo[i].lfork = &(mutex[i + 1]);
		philo[i].data->philo_list = philo;
		if (pthread_create(&(philo[i].tid), NULL, f_philo, &(philo[i])))
			return (1);
		pthread_detach(philo[i].tid);
	}
	return (0);
}
