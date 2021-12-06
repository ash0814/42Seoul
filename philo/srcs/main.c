/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:40:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/06 11:28:13 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int monitor_thread(t_philo *philo)
{
	int i;
	unsigned long long now;

	while(1)
	{
		i = 0;
		while (i < philo->data->p_cnt)
		{
			now = get_time();
			if (now > philo[i].data->die_t + philo[i].data->start_t)
			{
				printf("%d is dead\n", philo[i].philo_num);
				return (1);
			}
			if (philo[i].eat_count == philo[i].data->must_eat_cnt)
				return (1);
			i++;
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)malloc(sizeof(t_data));
	if(!data || !init_data(argc, argv, data))
		return (1);
	philo = (t_philo *)malloc(sizeof(t_philo) * data->p_cnt);
	if (!philo)
		return (1);
	philo->data = data;
	if (!init_philo(philo))
		return (1);
	if (start_thread(philo))
		return (1);
	if (monitor_thread(philo))
	{
		free_data(data, philo);
		return (0);
	}
	free_data(data, philo);
	return (0);
}
