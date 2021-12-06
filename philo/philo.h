/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:38:26 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/06 11:30:41 by sehyan           ###   ########.fr       */
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

typedef struct	s_data
{
	int					p_cnt;	//철학자 몇명
	unsigned long long	die_t;	//안먹으면 죽는 시간
	unsigned long long	eat_t;	//먹는 시간
	unsigned long long	sleep_t;	//자는 시간
	int					must_eat_cnt;	//먹으면 끝나는 횟수
	unsigned long long	start_t; //시작 시간
}				t_data;

typedef struct	s_philo
{
	pthread_t			tid;
	int					eat_count;	//먹은 횟수
	unsigned long long	last_eat_time; //마지막으로 먹은 시간
	int					philo_num; //철학자 출석번호
	pthread_mutex_t		*rfork;
	pthread_mutex_t		*lfork;
	t_data				*data;
}				t_philo;

int		ft_atoi(const char *str);
int		init_data(int argc, char **argv, t_data *data);
int		init_philo(t_philo *philo);
void	*f_philo(void *philo);

void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);

int		start_thread(t_philo *philo);
void	free_data(t_data *data, t_philo *philo);
void	eating(t_philo *philo);
int init_mutex(pthread_mutex_t **mutex, int num);
/*
utils
*/
int	ft_strlen(char *s);
unsigned long long get_time(void);

#endif
