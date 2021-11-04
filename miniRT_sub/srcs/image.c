/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:43:51 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/23 14:39:55 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			write_color(int t, t_color *pixel_color)
{
	return (t << 24 | (int)(255.999 * pixel_color->x) << 16 |
			(int)(255.999 * pixel_color->y) << 8 |
			(int)(255.999 * pixel_color->z));
}

t_data		print_image(t_vars *vars)
{
	t_data		image;
	t_color		color;
	int			i[2];
	t_camera	*cam;

	cam = (t_camera *)vars->scene->camera->element;
	image.img = mlx_new_image(vars->mlx, vars->scene->canvas.width,
							vars->scene->canvas.height);
	image.addr = mlx_get_data_addr(image.img,
				&image.bits_per_pixel, &image.line_length, &image.endian);
	i[1] = vars->scene->canvas.height;
	while (--i[1] >= 0)
	{
		i[0] = -1;
		while (++i[0] < vars->scene->canvas.width)
		{
			vars->scene->ray = ray_primary(cam, (double)(i[0]) /
					(vars->scene->canvas.width - 1), (double)(i[1]) /
					(vars->scene->canvas.height - 1));
			color = ray_color(vars->scene);
			my_mlx_pixel_put(&image, i[0], vars->scene->canvas.height
					- 1 - i[1], write_color(0, &color));
		}
	}
	return (image);
}
