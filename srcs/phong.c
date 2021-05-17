/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:23:34 by ash               #+#    #+#             */
/*   Updated: 2021/05/17 23:30:46 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** 광원과 그림자를 처리해주는 함수(ambient + diffuse + specular)
*/

t_color			phong_lighting(t_scene *scene)
{
	t_color		light_color;
	t_object		*lights;

	light_color = color(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
		{
			if (in_shadow(lights->element, scene))
			{
				light_color = v_add(light_color, color(0, 0, 0));
				lights = lights->next;
				continue ;
			}
			light_color = v_add(light_color,
				diffuse_light(scene, lights->element));
			light_color = v_add(light_color,
				specular_light(scene, lights->element));
		}
		lights = lights->next;
	}
	light_color = v_add(light_color, scene->ambient);
	return (v_min(vv_mul(light_color, scene->rec.albedo), color(1, 1, 1)));
}

/*
** diffuse color 계산
*/

t_color			diffuse_light(t_scene *scene, t_light *light)
{
	t_color			diffuse;
	t_vec			light_dir;
	double			kd;

	light_dir = v_unit(v_sub(light->origin, scene->rec.p));
	kd = fmax(v_dot(scene->rec.normal, light_dir), 0.0);
	diffuse = vt_mul(light->light_color, kd);
	return (diffuse);
}

/*
** specular	color 계산
*/

t_color			specular_light(t_scene *scene, t_light *light)
{
	t_color		specular;
	t_vec			reflect_dir;
	double			spec;
	t_vec			light_dir;

	light_dir = v_unit(v_sub(light->origin, scene->rec.p));
	reflect_dir = v_unit(reflect(scene->ray.dir, scene->rec.normal));
	spec = pow(fmax(vdot(light_dir, reflect_dir), 0.0), 30);
	specular = vt_mul(vt_mul(light->light_color, 1.5), spec);
	return (specular);
}

/*
** 그림자 구현 함수
*/

t_bool				in_shadow(t_light *light, t_scene *scene)
{
	t_hit_record	rec;
	t_ray			light_ray;
	t_vec			light_dir;

	light_dir = v_sub(light->origin, scene->rec.p);
	light_ray = ray(v_add(scene->rec.p,
		vt_mul(v_unit(scene->rec.normal), EPSILON)), light_dir);
	rec.tmin = 0;
	rec.tmax = v_len(light_dir);
	if (hit(scene->world, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

/*
** 반사광 계산 함수
*/

t_vec				reflect(t_vec v, t_vec n)
{
	return (v_sub(v, vt_mul(n, v_dot(v, n) * 2)));
}