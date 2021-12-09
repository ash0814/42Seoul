/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:38:26 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/09 20:10:56 by sehyan           ###   ########.fr       */
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
	int					p_cnt;
	unsigned long long	die_t;
	unsigned long long	eat_t;
	unsigned long long	sleep_t;
	int					must_eat_cnt;
	unsigned long long	start_t;
	struct s_philo		*philo_list;
}				t_data;

typedef struct s_philo
{
	pthread_t			tid;
	int					eat_count;
	unsigned long long	last_eat_time;
	int					philo_num;
	pthread_mutex_t		*rfork;
	pthread_mutex_t		*lfork;
	t_data				*data;
}				t_philo;

int					ft_atoi(const char *str);
int					init_data(int argc, char **argv, t_data *data);
int					init_philo(t_philo *philo);
void				*f_philo(void *philo);

void				thinking(t_philo *philo);
void				sleeping(t_philo *philo);
void				eating(t_philo *philo);

int					start_thread(t_philo *philo);
void				free_data(t_data *data, t_philo *philo);
void				eating(t_philo *philo);
int					init_mutex(pthread_mutex_t **mutex, int num);

int					ft_strlen(char *s);
unsigned long long	get_time(void);

#endif
