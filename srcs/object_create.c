/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 02:05:48 by ash               #+#    #+#             */
/*   Updated: 2021/05/17 02:12:51 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"


t_object	*object(t_object_type type, void *element, t_color albedo)
{
	t_object	*new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->element = element;
	// new->albedo = albedo;
	new->next = NULL;
	return (new);
}

t_object	*oadd(t_object **list, t_object *new)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = new;
		return (*list);
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	return (*list);
}

t_object	*olast(t_object *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

t_light		*light_point(t_point l_org, t_color l_color, double bright_ratio)
{
	t_light	*light;

	if(!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light->origin = l_org;
	light->light_color = l_color;
	light->bright_ratio = bright_ratio;
	return (light);
}