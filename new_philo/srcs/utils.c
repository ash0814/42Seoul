/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:44:54 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/17 01:21:10 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int		err_int(char *s)
{
	printf("%s", s);
	return (1);
}

int		get_time(long long *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (1);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (0);
}
