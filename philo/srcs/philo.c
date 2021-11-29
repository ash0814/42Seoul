/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:57:53 by sehyan            #+#    #+#             */
/*   Updated: 2021/11/29 21:11:16 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eating(t_philo *philo)
{
	char	*str = "eating\n";

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
		eating(p);
		// sleeping(p);
		// thinking(p);
		
		if (p->eat_count == p->data->must_eat_cnt){
			printf("here\n");
			break;
		}
	}
	write(1, "====================\n", 21);
	return NULL;
}

int	start_thread(t_philo *philo)
{
	int i;

	i = -1;
	while (++i < philo->data->p_cnt)
	{
		if (pthread_create(&(philo[i].tid), NULL, f_philo, &(philo[i])))
			return (1);
		pthread_join(philo[i].tid, NULL);
	}
	return (0);
}