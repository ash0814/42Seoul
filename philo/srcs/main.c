/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:40:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/11/29 21:24:43 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int argc, char **argv)
{
	t_data *data;
	t_philo *philo;
	t_fork *fork;

	data = (t_data *)malloc(sizeof(t_data));
	if(!data || !init_data(argc, argv, data))
		return (1);
	philo = (t_philo *)malloc(sizeof(t_philo) * data->p_cnt);
	fork = (t_fork *)malloc(sizeof(t_fork) * data->p_cnt);
	philo->data = data;
	fork->data = data;
	printf("input : %d %d %d %d %d\n",
		data->p_cnt, data->die_t, data->eat_t, data->sleep_t, data->must_eat_cnt);

	if (start_thread(philo))
		return (1);
	free_data(data, philo, fork);
	// system("leaks philo");
	return (0);
}
