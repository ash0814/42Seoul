/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:14:17 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/16 20:28:36 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec vt_mul(t_vec v1, double t)
{
	t_vec out;
	
	out.x = v1.x * t;
	out.y = v1.y * t;
	out.z = v1.z * t;
	return (out);
}

t_vec		vv_mul(t_vec vec, t_vec vec2)
{
	vec.x *= vec2.x;
	vec.y *= vec2.y;
	vec.z *= vec2.z;
	return (vec);
}

t_vec v_div(t_vec v1, double t)
{
	t_vec out;
	
	out.x = v1.x * (1 / t);
	out.y = v1.y * (1 / t);
	out.z = v1.z * (1 / t);
	return (out);
}

double v_pow(t_vec v1)
{
	double len;
	len = (v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z);
	return (len);
}

double v_len(t_vec v1)
{
	double len;
	len = sqrt(vec_len_squared(v1));
	return (len);
}