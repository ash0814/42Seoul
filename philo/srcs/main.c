/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:40:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/03 22:44:56 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
	
	// system("leaks philo");
	free_data(data, philo);
	return (0);
}
