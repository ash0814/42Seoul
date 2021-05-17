/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:40:24 by ash               #+#    #+#             */
/*   Updated: 2021/05/18 01:16:52 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parse_cy(char **words, t_scene *scene)
{
	char	**tmp;
	t_point	cy_center;
	t_vec	cy_nor;
	t_color	cy_color;
	double	cy;

	if (ft_len_2D(words) != 6 || ft_atof(words[3]) < 0 || ft_atof(words[4]) < 0)
		ft_error("Parsing ERROR\n");
	tmp = ft_split(words[1], ',');
	cy_center = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[2], ',');
	check_three_nor(tmp);
	cy_nor = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[5], ',');
	check_three_double(tmp);
	cy_color = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	scene->world = oadd(&scene->world, 
					object(CYL, cylinder(cy_center, cy_nor, 
					ft_atof(words[3]), ft_atof(words[4]), cy_color)));
}