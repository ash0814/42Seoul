/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:17:58 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/26 19:49:28 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*p_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->i % 2)
	{
		usleep(100);
	}
	while (true)
	{
		if (usleep(50) == -1)
		{
			printf("usleep Error\n");
			return (NULL);
		}
		p_eat(philo);
		p_sleep(philo);
		p_think(philo);
	}
	return (NULL);
}

int	start_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_cnt)
	{
		if (pthread_create(&(philo[i].tid), NULL,
				p_routine, (void *)(&philo[i])))
			return (1);
		pthread_detach(philo[i].tid);
		i++;
	}
	return (0);
}
