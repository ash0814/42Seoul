/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:26:38 by ash               #+#    #+#             */
/*   Updated: 2021/05/23 15:29:05 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_error(char *s)
{
	write(1, "ERROR : ", 8);
	perror(s);
	exit(1);
}

void	double_free(char **str)
{
	int i;
	int h;

	i = 0;
	h = ft_len_split(str);
	while (i < h)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int		ft_len_split(char **str)
{
	int h;

	h = 0;
	while (str[h])
		h++;
	return (h);
}

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = v_dot(r->dir, rec->normal) < 0;
	rec->normal = (rec->front_face) ? rec->normal : vt_mul(rec->normal, -1);
}
