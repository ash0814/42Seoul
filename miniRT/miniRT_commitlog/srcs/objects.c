/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 02:05:14 by ash               #+#    #+#             */
/*   Updated: 2021/05/23 14:48:36 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_sphere	*sphere(t_point center, double radius, t_color color)
{
	t_sphere *sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	sp->r2 = radius * radius;
	sp->color = color;
	return (sp);
}

t_plane		*plane(t_point point, t_vec normal, t_color color)
{
	t_plane *pln;

	if (!(pln = (t_plane *)malloc(sizeof(t_plane))))
		return (NULL);
	pln->point = point;
	pln->normal = normal;
	pln->color = color;
	return (pln);
}

t_triangle	*triangle(t_point p1, t_point p2, t_point p3, t_color color)
{
	t_triangle	*triangle;

	if (!(triangle = (t_triangle *)malloc(sizeof(t_triangle))))
		return (NULL);
	triangle->color = color;
	triangle->p1 = p1;
	triangle->p2 = p2;
	triangle->p3 = p3;
	triangle->normal = v_unit(v_cross(v_unit(v_sub(p2, p1)),
				v_unit(v_sub(p3, p1))));
	return (triangle);
}

t_square	*square(t_point point, t_vec normal, double len, t_color color)
{
	t_square *squ;

	if (!(squ = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	squ->point = point;
	squ->normal = v_unit(normal);
	squ->len = len;
	squ->color = color;
	return (squ);
}

t_cylinder	*cylinder(t_point point, t_vec normal, double *num, t_color color)
{
	t_cylinder *cyl;

	if (!(cyl = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (NULL);
	cyl->normal = normal;
	cyl->point = point;
	cyl->radius = num[0];
	cyl->height = num[1];
	cyl->color = color;
	return (cyl);
}
