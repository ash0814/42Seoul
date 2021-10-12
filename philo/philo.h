/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:38:26 by sehyan            #+#    #+#             */
/*   Updated: 2021/10/12 19:21:51 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

typedef struct	s_philo
{
	pthread_t		tid;
	int				eat_count;
	unsigned int	last_eat_time;
	int				rfork_idx;
	int				lfork_idx;
}				t_philo;

typedef struct	s_fork
{
	int				fid;
	pthread_mutex_t	mtx;
	pthread_t		p_tid;
}				t_fork;

typedef struct	s_data
{
	int		p_cnt;
	int		die_t;
	int		eat_t;
	int		sleep_t;
	int		cnt_eat;
	t_philo	*philo;
	t_fork	*fork;
}				t_data;

int		ft_atoi(const char *str);
int		init_args(int argc, char **argv, t_data *args);

#endif
