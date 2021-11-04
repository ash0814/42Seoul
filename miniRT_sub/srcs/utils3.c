/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:41:08 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/21 19:44:01 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int			check_max_w(t_scene *scene, int a)
{
	if (a > scene->w)
		a = scene->w;
	return (a);
}

int			check_max_h(t_scene *scene, int b)
{
	if (b > scene->h)
		b = scene->h;
	return (b);
}
