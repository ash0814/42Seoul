/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:35:41 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/17 01:21:06 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_data
{
	int				philo_cnt;
	long long		die_t;
	long long		eat_t;
	long long		sleep_t;
	long long		start_t;
	int				must_eat_cnt;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_exec;
	struct s_philo	*philo_list;
	int				left_idx;
	int				right_idx;
}			t_data;

typedef struct s_philo
{
	pthread_t		tid;
	int				eat_cnt;
	long long		last_eat_time;
	int				philo_id;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	t_data			*data;
}			t_philo;

/*
 * init.c
 */

int		init(t_data *data, t_philo *philo, char **argv);

/*
 *  utils.c
 */

int		err_int(char *s);


#endif
