/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:12:01 by ash               #+#    #+#             */
/*   Updated: 2021/05/21 00:39:59 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	next_camera(t_vars vars)
{
	vars.scene->camera = olast(vars.scene->camera);
	if (vars.scene->camera == NULL)
		vars.scene->camera = vars.scene->camera;
}

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 8)
	{
		next_camera(*vars);
		mlx_put_image_to_window(
			vars->mlx, vars->win, vars->scene->camera, 0, 0);
	}
	return (0);
}

int exit_hook()
{
	exit(0);
}