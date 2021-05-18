/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:54:02 by ash               #+#    #+#             */
/*   Updated: 2021/05/18 14:40:48 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_camera	*camera(t_canvas canvas, t_point orig, t_vec nor, double fov)
{
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	cam->fov = fov;
	cam->org = orig;
	cam->viewport_w = 2 * tan(cam->fov * 3.14 / 360.0);
	cam->viewport_h = cam->viewport_w / canvas.aspect_ratio;
	cam->focal_len = 1.0;
	cam->hrzt = vec(cam->viewport_w, 0, 0);
	cam->vrtc = vec(0, cam->viewport_h, 0);
	cam->normal = nor;
	cam->left_bottom = v_sub(v_sub(v_sub(cam->org, v_div(cam->hrzt, 2)),
								v_div(cam->vrtc, 2)), vt_mul(cam->normal, -1));
	//카메라의 normal값, fov 는 어디서 어떻게 받는걸까?
	return (cam);
}