/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:21:46 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/23 14:41:50 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_scene			*scene_init(char *argv, int w, int h)
{
	t_scene		*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->camera = 0;
	scene->world = 0;
	scene->light = 0;
	scene->ambient.x = -1;
	scene->w = w;
	scene->h = h;
	parse(argv, scene);
	return (scene);
}
