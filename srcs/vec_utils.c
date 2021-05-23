/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:40:30 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/23 15:40:33 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec	vec(double x, double y, double z)
{
	t_vec out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}

t_color	color(double r, double g, double b)
{
	t_color out;

	out.x = r;
	out.y = g;
	out.z = b;
	return (out);
}

t_point	point(double x, double y, double z)
{
	t_point out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}

t_vec	v_add(t_vec v1, t_vec v2)
{
	t_vec out;

	out.x = v1.x + v2.x;
	out.y = v1.y + v2.y;
	out.z = v1.z + v2.z;
	return (out);
}

t_vec	v_sub(t_vec v1, t_vec v2)
{
	t_vec out;

	out.x = v1.x - v2.x;
	out.y = v1.y - v2.y;
	out.z = v1.z - v2.z;
	return (out);
}
