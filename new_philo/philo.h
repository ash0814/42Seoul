/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:35:41 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/26 17:31:10 by ash              ###   ########.fr       */
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
# include <stdbool.h>

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
	pthread_mutex_t	*fork;
}			t_data;

typedef struct s_philo
{
	pthread_t		tid;
	int				eat_cnt;
	long long		last_eat_time;
	int				philo_id;
	int				i;
	int				left;
	int				right;
	t_data			*data;
}			t_philo;

/*
 * init.c
 */

int		init_philo(t_philo *philo, t_data *data);
int		init_data(t_data *data, char **argv);

/*
 *  utils.c
 */

int			err_int(char *s);
long long	get_time(void);
int			ft_atoi(const char *str);
void		s_sleep(t_philo *philo, long long time, long long begin);
int			mutex_init(pthread_mutex_t **fork, int size);

/*
* philo.c
*/
int		start_thread(t_philo *philo);
void	*p_routine(void *p);

/*
* routine.c
*/
void	p_eat(t_philo *philo);
void	pickup(pthread_mutex_t *fork, t_philo *philo);
void	p_think(t_philo *philo);
void	p_sleep(t_philo *philo);

/*
 *  monitor.c
 */
int		monitor_thread(t_philo *philo);
int		is_finish(t_philo *philo);

#endif
