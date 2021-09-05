/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:40:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/09/03 16:01:20 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*test(void *data)
{
	int a = *(int *)data;
	printf("thread >> %d\n", a);
	return ((void *)a);
}

int main(int argc, char **argv)
{
	t_args	*args;
	pthread_t *th;
	int a = 100;
	
	args = (t_args *)malloc(sizeof(t_args));
	if(!args || init_args(argc, argv, args))
		return (1);
	printf("%d %d %d %d %d\n", args->philos, args->die_t, args->eat_t, args->sleep_t, args->must_t);
	if (pthread_create(th, NULL, test, (void *)&a) < 0)
    {
        perror("thread create error:");
        exit(0);
    }
	// free(args);
	// while (1)
	// ;
	return (0);
}
