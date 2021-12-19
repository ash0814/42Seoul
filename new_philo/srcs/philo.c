/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:17:58 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/19 16:55:10 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*p_routine(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;
	printf("philo_num : %d\n", philo->philo_id);
	return NULL;
}

int		start_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_cnt)
	{
		if (pthread_create(&(philo[i].tid), NULL, p_routine, &(philo[i])) &&
			pthread_detach(philo[i].tid) != 0)
			return (1);
		i++;
	}
	return (0);
}
