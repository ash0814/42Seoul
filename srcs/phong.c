/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:23:34 by ash               #+#    #+#             */
/*   Updated: 2021/05/23 15:08:18 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec		reflect(t_vec v, t_vec n)
{
	return (v_sub(v, vt_mul(n, v_dot(v, n) * 2)));
}

t_bool		in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color		point_light_get(t_scene *scene, t_light *light)
{
	t_color		diffuse;
	t_vec		light_dir;
	double		light_len;
	t_ray		light_ray;
	t_color		specular;

	light_dir = v_sub(light->origin, scene->rec.p);
	light_len = v_len(light_dir);
	light_dir = v_unit(light_dir);
	light_ray = ray(v_add(scene->rec.p, vt_mul(v_unit(scene->rec.normal),
					EPSILON)), light_dir);
	if (in_shadow(scene->world, light_ray, light_len))
		return (color(0, 0, 0));
	diffuse = vt_mul(light->light_color, fmax(v_dot(scene->rec.normal,
					light_dir), 0.0));
	specular = vt_mul(vt_mul(light->light_color, 0.7),
			pow(fmax(v_dot(v_unit(vt_mul(scene->ray.dir, -1)),
						v_unit(reflect(vt_mul(light_dir, -1),
								scene->rec.normal))), 0.0), 100));
	return (v_add(diffuse, specular));
}

t_color		phong_lighting(t_scene *scene)
{
	t_color		light_color;
	t_object	*lights;

	light_color = color(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = v_add(light_color,
					point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = v_add(light_color, scene->ambient);
	return (v_min(vv_mul(light_color, scene->rec.albedo), color(1, 1, 1)));
}
