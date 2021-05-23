/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:23:26 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/23 15:12:52 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bmp		set_bmp_h(t_scene *scene)
{
	t_bmp	bmp;

	bmp.file_h.sign1 = 'B';
	bmp.file_h.sign2 = 'M';
	bmp.file_h.file_size = 14 + 40 +
			(int)(scene->canvas.width) * (int)(scene->canvas.height) * 4;
	bmp.file_h.reserved1 = 0;
	bmp.file_h.reserved2 = 0;
	bmp.file_h.start_bmp = 14 + 40;
	bmp.info_h.size = 40;
	bmp.info_h.width = (int)(scene->canvas.width);
	bmp.info_h.height = (int)(scene->canvas.height);
	bmp.info_h.planes = 1;
	bmp.info_h.bitcount = 24;
	bmp.info_h.compression = 0;
	bmp.info_h.sizeimage = (4 * ((int)(scene->canvas.width + 3) / 4)) *
									(int)(scene->canvas.height);
	bmp.info_h.x_pelspermeter = (int)(scene->canvas.width);
	bmp.info_h.y_pelspermeter = (int)(scene->canvas.height);
	bmp.info_h.color_used = 0xffffff;
	bmp.info_h.color_important = 0;
	return (bmp);
}

t_color2	color2(double r, double g, double b)
{
	t_color2	c;

	c.x = r * 255.0;
	c.y = g * 255.0;
	c.z = b * 255.0;
	return (c);
}

void		save_image(t_scene *scene)
{
	int			fd;
	int			i[2];
	t_color		pixel_color;
	t_color2	tmp_color;
	t_bmp		bmp_h;

	fd = open("minirt.bmp", O_WRONLY | O_CREAT, 0644);
	bmp_h = set_bmp_h(scene);
	write(fd, &bmp_h, 54);
	i[0] = -1;
	while (++i[0] < scene->canvas.height)
	{
		i[1] = -1;
		while (++i[1] < scene->canvas.width)
		{
			scene->ray = ray_primary((t_camera *)(scene->head_cam->element),
					(double)i[1] / (scene->canvas.width - 1),
					(double)i[0] / (scene->canvas.height - 1));
			pixel_color = ray_color(scene);
			tmp_color = color2(pixel_color.x, pixel_color.y, pixel_color.z);
			write(fd, &tmp_color, 3);
		}
	}
	close(fd);
	exit(0);
}
