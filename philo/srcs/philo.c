/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:40:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/09/06 19:03:42 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *philo(void *data)
{
	int k;

	k = *((int *)data);
	printf(">> %d\n", k);
	return 0;
}

int main(int argc, char **argv)
{
	t_args	*args;
	struct timeval  tv;
	pthread_t thread_t;
    int status;
	int i = -1;

	args = (t_args *)malloc(sizeof(t_args));
	if(!args || init_args(argc, argv, args))
		return (1);
	usleep(100000);
	printf("%d %d %d %d %d\n", args->philos, args->die_t, args->eat_t, args->sleep_t, args->must_t);
	
	int a = 100;
		if (pthread_create(&thread_t, NULL, philo, (void *)&a) < 0)
		{
			perror("thread create error:");
			exit(0);
		}
	printf("thread_id = %lu\n", thread_t);
	pthread_join(thread_t, &status);
	return (0);
}
