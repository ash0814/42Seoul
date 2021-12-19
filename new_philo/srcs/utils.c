/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:44:54 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/20 01:33:30 by ash              ###   ########.fr       */
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
	*time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (0);
}

void	s_sleep(t_philo *philo, long long time, long long begin)
{
	long long now;

	while (true)
	{
		get_time(&now);
		if (now - begin >= time)
			break;
		if (usleep(10)== -1)
			pthread_mutex_unlock(&(philo->data->mutex_exec));
	}
}

int	ft_atoi(const char *str)
{
	int	m;
	int	result;
	int	i;

	m = 1;
	result = 0;
	i = 0;
	if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!('0' <= str[i] && str[i] <= '9' && str[i] != '\0'))
		return (-1);
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * m);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
