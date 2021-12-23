/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:40:34 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/23 17:16:02 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (argc == 5 || argc == 6)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (init_data(data, argv))
			return (1);
		philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_cnt);
		if (init_philo(philo, argv, data))
			return (1);
		if (start_thread(philo))
			return (err_int("Philo Error\n"));
		if (monitor_thread(philo))
			return (err_int ("Monitor Error\n"));
		pthread_mutex_lock(&data->mutex_exec);
		return (0);
	}
	else
		return (err_int("Input Error\n"));
	return (0);
}
