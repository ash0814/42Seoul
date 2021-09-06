/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:40:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/09/06 11:24:30 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// void	*test(void *data)
// {
// 	int a = *(int *)data;
// 	printf("thread >> %d\n", a);
// 	return ((void *)a);
// }

int main(int argc, char **argv)
{
	t_args	*args;
	pthread_t *th;
	int a = 100;
	struct timeval  tv;
	double begin, end;

	gettimeofday(&tv, NULL);
	begin = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;

	
	args = (t_args *)malloc(sizeof(t_args));
	if(!args || init_args(argc, argv, args))
		return (1);

	printf("%d %d %d %d %d\n", args->philos, args->die_t, args->eat_t, args->sleep_t, args->must_t);

	// if (pthread_create(th, NULL, test, (void *)&a) < 0)
    // {
    //     perror("thread create error:");
    //     exit(0);
    // }
	// free(args);
	gettimeofday(&tv, NULL);
	end = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
	printf("Execution time %f\n", (end - begin) / 1000);
	return (0);
}
