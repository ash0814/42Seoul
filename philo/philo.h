/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:38:26 by sehyan            #+#    #+#             */
/*   Updated: 2021/09/03 15:47:02 by ash              ###   ########.fr       */
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

typedef struct	s_args
{
	int		philos;
	int		die_t;
	int		eat_t;
	int		sleep_t;
	int		must_t;
}				t_args;


int		ft_atoi(const char *str);
int		init_args(int argc, char **argv, t_args *args);

#endif
