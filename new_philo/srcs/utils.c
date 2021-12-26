/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:44:54 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/26 16:31:26 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int		err_int(char *s)
{
	printf("%s", s);
	return (1);
}

long long		get_time(void)
{
	struct timeval	tv;
	long long time;

	if (gettimeofday(&tv, NULL) == -1)
		return (err_int("timeval ERROR"));
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	s_sleep(t_philo *philo, long long time, long long begin)
{
	while (true)
	{
		if (get_time() - begin >= time)
			break;
		if (usleep(10) == -1)
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

int		mutex_init(pthread_mutex_t **fork, int size)
{
	int		i;

	i = -1;
	*fork = malloc(sizeof(pthread_mutex_t) * size);
	if (!*fork)
		return (1);
	while (++i < size){
		pthread_mutex_init(&(*fork)[i], NULL);
	}
	return (0);
}