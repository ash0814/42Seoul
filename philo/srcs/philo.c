/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:57:53 by sehyan            #+#    #+#             */
/*   Updated: 2021/11/21 16:01:18 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*f_philo(void *data)
{
	t_data *d;

	d = (t_data *)data;
	printf("%d\n", d->p_cnt);
	return NULL;
}

int	start_thread(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->p_cnt)
	{
		if (pthread_create(&(data->philo[i].tid), NULL, f_philo, data))
			return (1);
	}
	usleep(50000);
	return (0);
}