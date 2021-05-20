/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:49:57 by ash               #+#    #+#             */
/*   Updated: 2021/05/20 15:44:31 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bool			check_tr(t_vec a, t_vec b, t_vec c, t_vec h)
{
	t_vec ab;
	t_vec ac;
	t_vec ah;

	ab = v_sub(b, a);
	ac = v_sub(c, a);
	ah = v_sub(h, a);
	if (v_dot(v_cross(ab, ac), v_cross(ah, ac)) < 0)
		return (FALSE);
	return (TRUE);
}
t_bool			is_inside(t_point p1, t_point p2, t_point p3, t_point p)
{
	if (!check_tr(p1, p2, p3, p))
		return (FALSE);
	if (!check_tr(p2, p3, p1, p))
		return (FALSE);
	if (!check_tr(p3, p1, p2, p))
		return (FALSE);
	if (!check_tr(p1, p3, p2, p))
		return (FALSE);
	if (!check_tr(p3, p2, p1, p))
		return (FALSE);
	if (!check_tr(p2, p1, p3, p))
		return (FALSE);
	return (TRUE);
}

t_bool			hit_triangle(t_ray *r, t_object *obj, t_hit_record *rec)
{
	double		t;
	double		denom;
	double		nom;
	t_point		p;
	t_triangle	*triangle;

	triangle = (t_triangle *)obj->element;
	denom = v_dot(triangle->normal, r->dir);
	if (fabs(denom) <= EPSILON)
		return (FALSE);
	nom = v_dot(v_sub(r->origin, triangle->p1), triangle->normal);
	t = -nom / denom;
	if (t <= EPSILON || t > rec->tmax)
		return (FALSE);
	p = ray_at(r, t);
	if (!(is_inside(triangle->p1, triangle->p2, triangle->p3, p)))
		return (FALSE);
	rec->t = t;
	rec->p = p;
	rec->normal = v_unit(triangle->normal);
	rec->albedo = triangle->color;
	set_face_normal(r, rec);
	return (TRUE);
}

t_bool			hit_cylinder(t_ray *r, t_object *obj, t_hit_record *rec)
{
	t_cylinder *cyl;
	double  a;
    double  b;
    double  c;
    double  d;

	cyl = (t_cylinder *)obj->element;
	rec->albedo = cyl->color;
	a = v_pow(v_sub(r->dir, vt_mul(cyl->normal, v_dot(cyl->normal, r->dir))));
    b = v_dot(v_sub(r->dir, vt_mul(cyl->normal, v_dot(cyl->normal, r->dir))),
                v_sub(v_sub(r->origin, cyl->point), vt_mul(cyl->normal, v_dot(cyl->normal,
                v_sub(r->origin, cyl->point)))));
    c = v_pow(v_sub(v_sub(r->origin, cyl->point), vt_mul(cyl->normal, v_dot(cyl->normal,
                v_sub(r->origin, cyl->point))))) - cyl->radius * cyl->radius;
    d = b * b - a * c;
    rec->t = (-b - sqrt(d)) / a;
	rec->t2 = (-b + sqrt(d)) / a;
    if (d < 0)
        return (FALSE);
	if (rec->t < rec->tmin || rec->t > rec->tmax)
		if (rec->t2 < rec->tmin || rec->t2 > rec->tmax)
			return (FALSE);
	rec->p = ray_at(r, rec->t);
    // rec->normal = v_unit(v_div(v_sub(v_sub(rec->p, cyl->point), vt_mul(cyl->normal,
    //                 v_dot(cyl->normal, v_sub(rec->p, cyl->point)))), cyl->radius));
	rec->normal = v_unit(v_sub(v_sub(rec->p, cyl->point),
			vt_mul(cyl->normal, v_dot(cyl->normal, v_sub(rec->p, cyl->point)))));
   
	double pc2 = v_pow(v_sub(rec->p, cyl->point));
	double r2 = cyl->radius * cyl->radius;
	double h = sqrt(pc2 - r2);
	if (h > cyl->height)	//원기둥 길이
	{
		rec->p = ray_at(r, rec->t2);
		pc2 = v_pow(v_sub(rec->p, cyl->point));
		h = sqrt(pc2 - r2);
		if (h > cyl->height)
			return (FALSE);
	}
	set_face_normal(r, rec);
    return (TRUE);
}