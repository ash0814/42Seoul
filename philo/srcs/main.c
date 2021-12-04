/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:40:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/04 12:19:52 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int monitor_thread(t_philo *philo)
{
	int i = 0;

	while(1)
	{
		while (i < philo->data->p_cnt)
		{
			if (philo[i].last_eat_time > philo[i].data->die_t + philo[i].data->start_t)
			{
				printf("%llu : %llu : %llu\n", philo[i].last_eat_time, philo[i].data->start_t, philo[i].data->die_t);
				printf("%d is dead\n", philo[i].philo_num);
				// exit(1);
				return (1);
			}
			if (philo[i].eat_count == philo[i].data->must_eat_cnt)
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data *data;
	t_philo *philo;

	data = (t_data *)malloc(sizeof(t_data));
	if(!data || !init_data(argc, argv, data))
		return (1);
	philo = (t_philo *)malloc(sizeof(t_philo) * data->p_cnt);
	philo->data = data;
	if (!philo || !init_philo(philo))
		return (1);
	printf("input : %d %llu %llu %llu %d\n",
		data->p_cnt, data->die_t, data->eat_t, data->sleep_t, data->must_eat_cnt);

	if (start_thread(philo))
		return (1);
	if (monitor_thread(philo))
	{
		free_data(data, philo);
		return (0);
	}
	// join_thread(philo);
	// system("leaks philo");
	free_data(data, philo);
	return (0);
}
