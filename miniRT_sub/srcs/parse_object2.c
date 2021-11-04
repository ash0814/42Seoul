/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:40:24 by ash               #+#    #+#             */
/*   Updated: 2021/05/27 10:30:45 by sehyan           ###   ########.fr       */
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

	if (len_spl(words) != 6 || ft_atof(words[3]) < 0 || ft_atof(words[4]) < 0)
		ft_error("CY Parsing ERROR\n");
	if (len_spl((tmp = ft_split(words[1], ','))) != 3)
		ft_error("point, color, vec don't have 3 value\n");
	cy_center = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[2], ',');
	check_three_nor(tmp);
	cy_nor = v_unit(vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])));
	double_free(tmp);
	tmp = ft_split(words[5], ',');
	check_color(tmp);
	cy_color = color(ft_atof(tmp[0]) / 255.0, ft_atof(tmp[1]) / 255.0,
			ft_atof(tmp[2]) / 255.0);
	double_free(tmp);
	cy[0] = ft_atof(words[3]);
	cy[1] = ft_atof(words[4]);
	obj_add_back(&scene->world,
			object(CYL, cylinder(cy_center, cy_nor, cy, cy_color)));
}

void	parse_pl(char **words, t_scene *scene)
{
	char	**tmp;
	t_point	pl_point;
	t_vec	pl_nor;
	t_color	pl_color;

	if (len_spl(words) != 4)
		ft_error("PL Parsing ERROR\n");
	tmp = ft_split(words[1], ',');
	if (len_spl(tmp) != 3)
		ft_error("point, color, vec don't have 3 value\n");
	pl_point = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[2], ',');
	check_three_nor(tmp);
	pl_nor = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[3], ',');
	check_color(tmp);
	pl_color = color(ft_atof(tmp[0]) / 255.0, ft_atof(tmp[1]) / 255.0,
			ft_atof(tmp[2]) / 255.0);
	double_free(tmp);
	obj_add_back(&scene->world, object(PLN, plane(pl_point, pl_nor, pl_color)));
}

void	parse_sp(char **words, t_scene *scene)
{
	char	**tmp;
	t_point	sp_p;
	double	rad;
	t_color	sp_color;

	if (len_spl(words) != 4 || ft_atof(words[2]) <= 0)
		ft_error("SP Parsing ERROR\n");
	tmp = ft_split(words[1], ',');
	if (len_spl(tmp) != 3)
		ft_error("point, color, vec don't have 3 value\n");
	sp_p = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[3], ',');
	check_color(tmp);
	sp_color = color(ft_atof(tmp[0]) / 255.0, ft_atof(tmp[1]) / 255.0,
			ft_atof(tmp[2]) / 255.0);
	double_free(tmp);
	rad = ft_atof(words[2]) / 2.0;
	oadd(&scene->world, object(SP, sphere(sp_p, rad, sp_color)));
}

void	parse_sq(char **words, t_scene *scene)
{
	char	**tmp;
	t_point	sq_p;
	t_color	sq_color;
	t_vec	sq_nor;
	double	sq_len;

	if (len_spl(words) != 5 || ft_atof(words[3]) <= 0)
		ft_error("SQ Parsing ERROR\n");
	tmp = ft_split(words[1], ',');
	if (len_spl(tmp) != 3)
		ft_error("point, color, vec don't have 3 value\n");
	sq_p = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[2], ',');
	check_three_nor(tmp);
	sq_nor = v_unit(vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2])));
	double_free(tmp);
	tmp = ft_split(words[4], ',');
	check_color(tmp);
	sq_color = color(ft_atof(tmp[0]) / 255.0, ft_atof(tmp[1]) / 255.0,
			ft_atof(tmp[2]) / 255.0);
	double_free(tmp);
	sq_len = ft_atof(words[3]);
	obj_add_back(&scene->world, object(SQU, square(sq_p, sq_nor, sq_len,
					sq_color)));
}

void	parse_tr(char **words, t_scene *scene)
{
	char	**tmp;
	t_point	tr_p[3];
	t_color tr_color;

	if (len_spl(words) != 5)
		ft_error("TR Parsign ERROR\n");
	if (len_spl((tmp = ft_split(words[1], ','))) != 3)
		ft_error("point, color, vec don't have 3 value\n");
	tr_p[0] = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	if (len_spl((tmp = ft_split(words[2], ','))) != 3)
		ft_error("point, color, vec don't have 3 value\n");
	tr_p[1] = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	if (len_spl((tmp = ft_split(words[3], ','))) != 3)
		ft_error("point, color, vec don't have 3 value\n");
	tr_p[2] = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[4], ',');
	check_color(tmp);
	tr_color = color(ft_atof(tmp[0]) / 255.0, ft_atof(tmp[1]) / 255.0,
			ft_atof(tmp[2]) / 255.0);
	double_free(tmp);
	obj_add_back(&scene->world, object(TRI, triangle(tr_p[0], tr_p[1],
					tr_p[2], tr_color)));
}
