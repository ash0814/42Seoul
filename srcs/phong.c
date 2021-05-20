/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:23:34 by ash               #+#    #+#             */
/*   Updated: 2021/05/20 15:28:29 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// /*
// ** 광원과 그림자를 처리해주는 함수(ambient + diffuse + specular)
// */

// t_color			phong_lighting(t_scene *scene)
// {
// 	t_color		light_color;
// 	t_object		*lights;

// 	light_color = color(0, 0, 0);
// 	lights = scene->light;
// 	while (lights)
// 	{
// 		if (lights->type == LIGHT_POINT)
// 		{
// 			if (in_shadow(lights->element, scene))
// 			{
// 				light_color = v_add(light_color, color(0, 0, 0));
// 				lights = lights->next;
// 				continue ;
// 			}
// 			light_color = v_add(light_color,
// 				diffuse_light(scene, lights->element));
// 			light_color = v_add(light_color,
// 				specular_light(scene, lights->element));
// 		}
// 		lights = lights->next;
// 	}
// 	light_color = v_add(light_color, scene->ambient);
// 	return (v_min(vv_mul(light_color, scene->rec.albedo), color(1, 1, 1)));
// }

// /*
// ** diffuse color 계산
// */

// t_color			diffuse_light(t_scene *scene, t_light *light)
// {
// 	t_color			diffuse;
// 	t_vec			light_dir;
// 	double			kd;

// 	light_dir = v_unit(v_sub(light->origin, scene->rec.p));
// 	kd = fmax(v_dot(scene->rec.normal, light_dir), 0.0);
// 	diffuse = vt_mul(light->light_color, kd);
// 	return (diffuse);
// }

// /*
// ** specular	color 계산
// */

// t_color			specular_light(t_scene *scene, t_light *light)
// {
// 	t_color		specular;
// 	t_vec			reflect_dir;
// 	double			spec;
// 	t_vec			light_dir;

// 	light_dir = v_unit(v_sub(light->origin, scene->rec.p));
// 	reflect_dir = v_unit(reflect(scene->ray.dir, scene->rec.normal));
// 	spec = pow(fmax(v_dot(light_dir, reflect_dir), 0.0), 30);
// 	specular = vt_mul(vt_mul(light->light_color, 1.5), spec);
// 	return (specular);
// }

// /*
// ** 그림자 구현 함수
// */

// t_bool				in_shadow(t_light *light, t_scene *scene)
// {
// 	t_hit_record	rec;
// 	t_ray			light_ray;
// 	t_vec			light_dir;

// 	light_dir = v_sub(light->origin, scene->rec.p);
// 	light_ray = ray(v_add(scene->rec.p,
// 		vt_mul(v_unit(scene->rec.normal), EPSILON)), light_dir);
// 	rec.tmin = 0;
// 	rec.tmax = v_len(light_dir);
// 	if (hit(scene->world, &light_ray, &rec))
// 		return (TRUE);
// 	return (FALSE);
// }

// /*
// ** 반사광 계산 함수
// */

// t_vec				reflect(t_vec v, t_vec n)
// {
// 	return (v_sub(v, vt_mul(n, v_dot(v, n) * 2)));
// }


t_vec			reflect(t_vec v, t_vec n)
{
	//v - 2 * dot(v, n) * n;
	return (v_sub(v, vt_mul(n, v_dot(v, n) * 2)));
}

t_bool			in_shadow(t_object *objs, t_ray light_ray, double light_len)
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
	double		kd; // diffuse의 강도
	double		light_len;
	t_ray		light_ray;
	t_color		specular;
	t_vec		view_dir;
	t_vec		reflect_dir;
	double		spec;
	double		ksn;
	double		ks;

	light_dir = v_sub(light->origin, scene->rec.p);
	light_len = v_len(light_dir);
	light_dir = v_unit(light_dir);
	light_ray = ray(v_add(scene->rec.p, vt_mul(v_unit(scene->rec.normal), 
					EPSILON)), light_dir);
	if (in_shadow(scene->world, light_ray, light_len))
		return (color(0,0,0));
	kd = fmax(v_dot(scene->rec.normal, light_dir), 0.0);
	diffuse = vt_mul(light->light_color, kd);
	view_dir = v_unit(vt_mul(scene->ray.dir, -1));
	reflect_dir = v_unit(reflect(vt_mul(light_dir, -1), scene->rec.normal));
	ksn = 100; // shininess value
	ks = 0.7; // specular strength
	spec = pow(fmax(v_dot(view_dir, reflect_dir), 0.0), ksn);
	specular = vt_mul(vt_mul(light->light_color, ks), spec);
	// return (specular);
	// return (diffuse);
	// vec_print("spc", specular);
	// vec_print("dif", diffuse);
	return (v_add(diffuse, specular));
}

t_color		phong_lighting(t_scene *scene)
{
	t_color	light_color;
	t_object	*lights;

	light_color =  color(0, 0, 0); //광원이 하나도 없다면, 빛의 양은 (0, 0, 0)일 것이다.
	lights = scene->light;
	while (lights) //여러 광원에서 나오는 모든 빛에 대해 각각 diffuse, specular 값을 모두 구해줘야 한다
	{
		if(lights->type == LIGHT_POINT)
			light_color = v_add(light_color,
					point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = v_add(light_color, scene->ambient);
	return (v_min(vv_mul(light_color, scene->rec.albedo), color(1, 1, 1)));
}