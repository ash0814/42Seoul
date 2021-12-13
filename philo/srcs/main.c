/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:40:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/13 20:52:06 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int philo_eat_finish(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->p_cnt)
	{
		if (philo[i].is_finish == 0)
			return (0);
		i++;
	}
	return (1);
}

int	monitor_thread(t_philo *philo)
{
	int					i;
	long long	now;

	while (1)
	{
		i = 0;
		while (i < philo->data->p_cnt)
		{
			if (philo_eat_finish(philo))
				return (1);
			now = get_time();
			if (now - philo[i].last_eat_time > philo[i].data->die_t
				&& philo[i].last_eat_time != 0)
			{
				printf("%llu %d died\n",
					now - philo[i].data->start_t, philo[i].philo_num);
				return (1);
			}
			if (philo[i].eat_count == philo[i].data->must_eat_cnt)
				philo[i].is_finish = 1;
			i++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data || !init_data(argc, argv, data))
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
