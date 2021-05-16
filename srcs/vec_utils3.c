/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:14:59 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/16 20:41:38 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	v_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	v_cross(t_vec v1, t_vec v2)
{
	t_vec out;

	out.x = v1.y * v2.z - v1.z * v2.y;
	out.y = v1.z * v2.x - v1.x * v2.z;
	out.z = v1.x * v2.y - v1.y * v2.x;
	return (out);
}

t_vec	v_unit(t_vec v)
{
	double len;

	len = v_len(v);
	return (vec(v.x / len, v.y / len , v.z / len));
}

t_vec	v_min(t_vec vec1, t_vec vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}