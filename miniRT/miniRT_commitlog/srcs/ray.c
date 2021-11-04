/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:40:24 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/23 15:40:27 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_ray		ray(t_point origin, t_vec dir)
{
	t_ray ray;

	ray.origin = origin;
	ray.dir = v_unit(dir);
	return (ray);
}

t_vec		ray_at(t_ray *ray, double t)
{
	t_vec out;

	out.x = ray->origin.x + ray->dir.x * t;
	out.y = ray->origin.y + ray->dir.y * t;
	out.z = ray->origin.z + ray->dir.z * t;
	return (out);
}

t_color		ray_color(t_scene *scene)
{
	scene->rec.tmin = EPSILON;
	scene->rec.tmax = INFINITY;
	if (hit(scene->world, &scene->ray, &scene->rec))
	{
		return (phong_lighting(scene));
	}
	else
	{
		return (color(0, 0, 0));
	}
}

t_ray		ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam->org;
	ray.dir = v_unit(v_sub(v_add(v_add(cam->left_bottom, vt_mul(cam->hrzt, u)),
					vt_mul(cam->vrtc, v)), cam->org));
	return (ray);
}
