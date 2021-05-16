/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:54:02 by ash               #+#    #+#             */
/*   Updated: 2021/05/17 02:03:30 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_camera	*camera(t_canvas canvas, t_point orig)
{
	t_camera	*cam;
	double		focal_len;
	double		viewport_height;

	cam = (t_camera *)malloc(sizeof(t_camera));
	viewport_height = 2.0;
	focal_len = 1.0;
	cam->org = orig;
	cam->viewport_h = viewport_height;
	cam->viewport_w = viewport_height * canvas.aspect_ratio;
	cam->focal_len = focal_len;
	cam->hrzt = vec(cam->viewport_w, 0, 0);
	cam->vrtc = vec(0, cam->viewport_h, 0);
	cam->left_bottom = v_sub(v_sub(v_sub(cam->org, v_div(cam->hrzt, 2)),
								v_div(cam->vrtc, 2)), vec(0, 0, focal_len));
    //카메라의 normal값, fov 는 어디서 어떻게 받는걸까?
	return (cam);
}