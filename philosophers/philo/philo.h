/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:38:26 by sehyan            #+#    #+#             */
/*   Updated: 2021/11/21 15:39:45 by ash              ###   ########.fr       */
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
	int				eat_count;	//먹은 횟수
	unsigned int	last_eat_time; //마지막으로 먹은 시간
	int				rfork_idx; //오른쪽 포크 인덱스
	int				lfork_idx; //왼쪽 포크 인덱스
}				t_philo;

typedef struct	s_fork
{
	int				fid; //포크아이디
	pthread_mutex_t	mtx; //뮤텍스객체
	pthread_t		p_tid; //잡고있는 철학자 tid
}				t_fork;

typedef struct	s_data
{
	int		p_cnt;	//철학자 몇명
	int		die_t;	//안먹으면 죽는 시간
	int		eat_t;	//먹는 시간
	int		sleep_t;	//자는 시간
	int		must_eat_cnt;	//먹으면 끝나는 횟수
	t_philo	*philo;
	t_fork	*fork;
}				t_data;

int		ft_atoi(const char *str);
int		init_data(int argc, char **argv, t_data *data);
int		init_philo(t_data *data);
void	*f_philo(void *data);
void	free_data(t_data *data);

int		start_thread(t_data *data);

#endif
