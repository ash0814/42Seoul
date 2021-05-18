/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:40:24 by ash               #+#    #+#             */
/*   Updated: 2021/05/18 12:14:53 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parse_cy(char **words, t_scene *scene)
{
	char	**tmp;
	t_point	cy_center;
	t_vec	cy_nor;
	t_color	cy_color;
	double	cy[2];

	if (ft_len_2D(words) != 6 || (cy[0] = ft_atof(words[3])) < 0
								|| (cy[1] = ft_atof(words[4])) < 0)
		ft_error("CY Parsing ERROR\n");
	tmp = ft_split(words[1], ',');
	cy_center = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[2], ',');
	check_three_nor(tmp);
	cy_nor = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[5], ',');
	check_color(tmp);
	cy_color = color(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	scene->world = oadd(&scene->world, 
					object(CYL, cylinder(cy_center, cy_nor, cy, cy_color)));
}

void	parse_pl(char **words, t_scene *scene)
{
	char **tmp;
	t_point	pl_point;
	t_vec	pl_nor;
	t_color	pl_color;

	if (ft_len_2D(words) != 4)
		ft_error("PL Parsing ERROR\n");
	tmp = ft_split(words[1], ',');
	pl_point = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[2], ',');
	check_three_nor(tmp);
	pl_nor = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[3], ',');
	check_color(tmp);
	pl_color = color(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	scene->world = oadd(&scene->world, object(PLN, plane(pl_point, pl_nor, pl_color)));
}

void	parse_sp(char **words, t_scene *scene)
{
	char	**tmp;
	t_point	sp_p;
	double	rad;
	t_color	sp_color;

	if (ft_len_2D(words) != 4 || ft_atof(words[2]) <= 0)
		ft_error("SP Parsing ERROR\n");
	tmp = ft_split(words[1], ',');
	sp_p = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[3], ',');
	check_color(tmp);
	sp_color = color(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	rad = ft_atof(words[2]);
	scene->world = oadd(&scene->world, object(SP, sphere(sp_p, rad, sp_color)));
}

void	parse_sq(char **words, t_scene *scene)
{
	char	**tmp;
	t_point	sq_p;
	t_color	sq_color;
	t_vec	sq_nor;
	double	sq_len;

	if (ft_len_2D(words) != 5 || ft_atof(words[3]) <= 0)
		ft_error("SQ Parsing ERROR\n");
	tmp = ft_split(words[1], ',');
	sq_p = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[2], ',');
	check_three_nor(tmp);
	sq_nor = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[4], ',');
	check_color(tmp);
	sq_color = color(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	sq_len = ft_atof(words[3]);
	scene->world = oadd(&scene->world, object(SQU, square(sq_p, sq_nor, sq_len, sq_color)));
}

void	parse_tr(char **words, t_scene *scene)
{
	char	**tmp;
	t_point	tr_p[3];
	t_color tr_color;

	if (ft_len_2D(words) != 5)
		ft_error("TR Parsign ERROR\n");
	tmp = ft_split(words[1], ',');
	tr_p[0] = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[2], ',');
	tr_p[1] = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[3], ',');
	tr_p[2] = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[4], ',');
	check_color(tmp);
	tr_color = color(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	scene->world = oadd(&scene->world, object(TRI, triangle(tr_p[0], tr_p[1], tr_p[2], tr_color)));
}