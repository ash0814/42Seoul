/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:54:02 by ash               #+#    #+#             */
/*   Updated: 2021/05/21 13:57:22 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_camera	*camera(t_canvas canvas, t_point org, t_vec nor, double fov)
{
	t_camera	*cam;
	t_vec		vup;

	cam = (t_camera *)malloc(sizeof(t_camera));
	cam->fov = fov;
	cam->org = org;
	cam->viewport_w = 2 * tan(cam->fov * 3.14 / 360.0);
	cam->viewport_h = cam->viewport_w / canvas.aspect_ratio;
	cam->focal_len = 1.0;
	cam->normal = nor;
	vup = vec(0, 1, 0);
	if (cam->normal.x == 0 && fabs(cam->normal.y) == 1
								&& cam->normal.z == 0)
		vup = vec(1, 0, 0);
	cam->hrzt =
		vt_mul(v_unit(v_cross(cam->normal, vup)), cam->viewport_w);
	cam->vrtc =
		vt_mul(v_unit(v_cross(cam->hrzt, cam->normal)), cam->viewport_h);
	cam->left_bottom =
		v_sub(v_sub(v_sub(cam->org, v_div(cam->hrzt, 2)),
		v_div(cam->vrtc, 2)), vt_mul(cam->normal, -1));
	return (cam);
}