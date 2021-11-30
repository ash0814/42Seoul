/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:57:53 by sehyan            #+#    #+#             */
/*   Updated: 2021/11/30 17:47:41 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	pickup(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	printf("pickup right\n");
	pthread_mutex_lock(philo->lfork);
	printf("pickup left\n");
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
	write(1, "sleeping\n", 9);
}

void	thinking(t_philo *philo)
{
	write(1, "thinking\n", 9);
}

void	*f_philo(void *philo)
{
	t_philo *p;

	p = (t_philo *)philo;
	while (1)
	{
		pickup(p);
		if (p->eat_count == p->data->must_eat_cnt){
			break;
		}
	}
	write(1, "====================\n", 21);
	return NULL;
}

int	start_thread(t_philo *philo)
{
	int i;
	pthread_mutex_t *mutex;
	int *status;

	if (init_mutex(mutex, philo->data->p_cnt))
		return (1);
	i = -1;
	while (++i < philo->data->p_cnt)
	{
		philo[i].philo_num = i + 1;
		if (i == 0)
		philo[i].rfork = &mutex[philo->data->p_cnt - 1];
		else
			philo[i].rfork = &mutex[i - 1];
		philo[i].lfork = &mutex[i];
		
		if (pthread_create(&(philo[i].tid), NULL, f_philo, &(philo[i])))
		{
			return (1);
		}
		pthread_join(philo[i].tid, (void **)&status);
	}
	return (0);
}