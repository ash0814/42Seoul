/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:33:16 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/17 01:21:04 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int		init_philo(t_philo *philo, char **argv, t_data *data)
{
}

int		init_data(t_data *data, char **argv)
{
	pthread_mutex_init(data->mutex_print);
	pthread_mutex_init(data->mutex_exec);
	pthread_mutex_lock(data->mutex_exec);
	
}

int		init(t_data *data, t_philo *philo, char **argv)
{
	data = (t_data *)malloc(sizeof(t_data));
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!data || !philo)
		return (1);
	if (init_data(data, argv) || init_philo(philo, argv, data))
		return (1);
}
