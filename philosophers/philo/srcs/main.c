/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:40:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/11/22 20:59:35 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int argc, char **argv)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if(!data || !init_data(argc, argv, data))
		return (1);
	
	// printf("input : %d %d %d %d %d\n", data->p_cnt, data->die_t, data->eat_t, data->sleep_t, data->must_eat_cnt);

	if (start_thread(data))
		return (1);
	free_data(data);
	// system("leaks philo");
	return (0);
}
