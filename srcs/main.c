/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:55:42 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/17 21:17:40 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bool		check_rt(char *s)
{
	int i;

	i = ft_strlen(s);
	if (!(s[--i] == 't' && s[--i] == 'r' && s[--i] == '.'))
		return (FALSE);
	else
		return (TRUE);
}

void			check_window_size(t_vars vars)
{
	int			x;
	int			y;

	mlx_get_screen_size(vars.mlx, &x, &y);
	if (vars.scene->canvas.width > x)
		vars.scene->canvas.width = x;
	if (vars.scene->canvas.height > y)
		vars.scene->canvas.height = y;
}

int			print_image(t_vars *vars)
{
	t_data	image;
	t_color color;
	double	u;
	double	v;
	int 	i;
	int		j;

	vars->win = mlx_new_window(vars->mlx, vars->scene->canvas.width,
							vars->scene->canvas.height, "ash_world!");
	image.img = mlx_new_image(vars->mlx, vars->scene->canvas.width,
							vars->scene->canvas.height);
	image.addr = mlx_get_data_addr(image.img,
				&image.bits_per_pixel, &image.line_length, &image.endian);
	j = vars->scene->canvas.height-1;
	while (j >= 0)
	{
		i = -1;
		while(++i < vars->scene->canvas.width)
		{
			u = (double) (i) / (vars->scene->canvas.width-1);
			v = (double)(j) / (vars->scene->canvas.height-1);
			vars->scene->ray = ray_primary(vars->scene->camera, u, v);
			color = ray_color(vars->scene);
			my_mlx_pixel_put(&image, i, vars->scene->canvas.height - 1 - j, write_color(0, &color));
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, image.img, 0, 0);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, (1L << 5), exit_hook, 0);
	mlx_loop(vars->mlx);
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
		ft_error("input ERROR\n");
	check_window_size(vars);
	print_image(&vars);
	return (0);
}	
