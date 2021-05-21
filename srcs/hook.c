/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:12:01 by ash               #+#    #+#             */
/*   Updated: 2021/05/21 19:24:25 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void			next_camera(t_vars vars)
{
	vars.scene->camera = cam_onext(vars.scene->camera);
	if (vars.scene->camera == NULL)
		vars.scene->camera = vars.scene->head_cam;
}

t_object        *cam_onext(t_object *list)
{
    if (list->next == NULL)
	    return (NULL);
    if (list->next)
        return (list->next);
    return (NULL);
}

int	key_hook(int keycode, t_vars *vars)
{
	t_data image;

	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 8)
	{
		next_camera(*vars);
		image = print_image(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, image.img, 0, 0);
	}
	return (0);
}

int exit_hook()
{
	exit(0);
}