/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:40:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/09/06 15:38:03 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *philo(void *data)
{
	printf(">> %d\n", data);
	return 0;
}

int main(int argc, char **argv)
{
	t_args	*args;
	struct timeval  tv;
	pthread_t thread_t;
    int status;

	args = (t_args *)malloc(sizeof(t_args));
	if(!args || init_args(argc, argv, args))
		return (1);
	usleep(100000);
	printf("%d %d %d %d %d\n", args->philos, args->die_t, args->eat_t, args->sleep_t, args->must_t);
	
	if (pthread_create(&thread_t, NULL, philo, (void *)&args->die_t) < 0)
    {
        perror("thread create error:");
        exit(0);
    }
	// free(args);
	return (0);
}
