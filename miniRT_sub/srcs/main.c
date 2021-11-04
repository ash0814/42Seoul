/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:55:42 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/27 10:57:35 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

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
	t_vars	vars;
	t_data	image;
	int		w;
	int		h;

	vars.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx, &w, &h);
	if ((argc == 2 || argc == 3) && check_rt(argv[1]) == TRUE)
		vars.scene = scene_init(argv[1], w, h);
	else
		ft_error("input ERROR\n");
	printf("===MAKE MINIRT===\n");
	vars.win = mlx_new_window(vars.mlx,
			vars.scene->canvas.width, vars.scene->canvas.height, "ash_world!");
	image = print_image(&vars);
	if ((argc == 3) && (!ft_strcmp(argv[2], "--save") ||
				!ft_strcmp(argv[2], "--s")) && printf("===MAKE BMP FILE===\n"))
		save_image(vars.scene);
	else if (argc == 3)
		ft_error("input ERROR\n");
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}
