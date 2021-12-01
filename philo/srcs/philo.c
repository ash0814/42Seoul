/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:57:53 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/01 21:25:51 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	pickup(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	printf("%d pickup right\n", philo->philo_num);
	pthread_mutex_lock(philo->lfork);
	printf("%d pickup left\n", philo->philo_num);
	eating(philo);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	eating(t_philo *philo)
{
	char	*str = " eating\n";

	char s = philo->philo_num + 48;

	write(1, &s, 1);
	write(1, str, ft_strlen(str));
	philo->eat_count++;
}

void	sleeping(t_philo *philo)
{
	printf("%d sleeping\n", philo->philo_num);
}

void	thinking(t_philo *philo)
{
	printf("%d thinking\n", philo->philo_num);
}

void	*f_philo(void *philo)
{
	t_philo *p;

	p = (t_philo *)philo;
	while (1)
	{
		pickup(p);
		sleeping(p);
		thinking(p);
		if (p->eat_count == p->data->must_eat_cnt){
			break;
		}
	}
	// write(1, "====================\n", 21);
	return (philo);
}

int join_thread(t_philo *philo)
{
	int i;
	void *status;

	i = -1;
	while (++i < philo->data->p_cnt)
	{
		pthread_join(philo[i].tid, &status);
	}
	return (0);
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
		// pthread_join(philo[i].tid, &status);
	}
	join_thread(philo);
	return (0);
}