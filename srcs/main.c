/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:55:42 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/16 21:43:33 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool		check_rt(char *s)
{
	int i;

	i = ft_strlen(s);
	if (!(s[--i] == 't' && s[--i] == 'r' && s[--i] == '.'))
		return (FALSE);
	else
		return (TRUE);
}

int			main(int argc, char *argv[])
{
	int fd;
	char buf[5000000];
	t_vars vars;

	vars.mlx = mlx_init();
	if ((argc == 2 || argc == 3) && check_rt(argv[1]) == TRUE)
	{
		if (!(vars.scene = scene_init()))
			return (0);
		parse(argv[1], &vars.scene);
	}
	else
	{
		printf("inputError\n");
		return (0);
	}
	return (0);
	// if (argc == 2 || argc == 3)
	// {
	// 	if (argc == 3) // --save
	// 	{
	// 		if (check_rt(argv[2]) == FALSE)
	// 			return (0);
	// 		fd = open(argv[2], O_RDONLY);
	// 		read(fd, buf, 5000000);
	// 		parse(buf, &vars);
	// 	}
	// 	else if (argc == 2)
	// 	{
	// 		if (check_rt(argv[1]) == FALSE)
	// 			return (0);
	// 		fd = open(argv[1], O_RDONLY);
	// 		read(fd, buf, 5000000);
	// 		parse(buf, &vars);
	// 	}
	// 	else
	// 	{
	// 		printf("inputError");
	// 		return (0);
	// 	}
	// }
	// else
	// {
	// 	printf("inputError");
	// 	return (0);
	// }

	return (0);
}