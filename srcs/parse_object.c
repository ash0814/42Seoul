/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:58:13 by ash               #+#    #+#             */
/*   Updated: 2021/05/18 17:01:57 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parse_r(char **words, t_scene *scene)
{
	if (ft_len_2D(words) != 3)
		ft_error("R Parsing ERROR\n");
	if (ft_atoi(words[1]) <= 0 || ft_atoi(words[2]) <= 0)
		ft_error("R parsing ERROR\n");
	scene->canvas = canvas(ft_atoi(words[1]), ft_atoi(words[2]));
}

void	parse_a(char **words, t_scene *scene)
{
	t_color		amb;
	char		**tmp;

	if (ft_len_2D(words) != 3)
		ft_error("A Parsing ERROR\n");
	if (ft_atof(words[1]) < 0.0 || ft_atof(words[1]) > 1.0)
		ft_error("A parsing ERROR\n");
	tmp = ft_split(words[2], ',');
	check_color(tmp);
	amb = color(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	scene->ambient = vt_mul(amb, ft_atof(words[1]));
}

void	parse_c(char **words, t_scene *scene)
{
	t_vec		cam_vec;
	t_point		cam_p;
	double		cam_fov;
	char 		**tmp;

	if (ft_len_2D(words) != 4)
		ft_error("C Parsing ERROR\n");
	if (ft_atof(words[3]) < 0.0 || ft_atof(words[3]) > 180.0)
		ft_error("FOV value is not in 0 ~ 180\n");
	tmp = ft_split(words[1], ',');
	cam_p = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	cam_fov = ft_atof(words[3]);
	tmp = ft_split(words[2], ',');
	check_three_nor(tmp);
	cam_vec = vec(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	obj_add_back(&scene->camera, object(CAM, camera(scene->canvas, cam_p, cam_vec, cam_fov)));
}

void	parse_l(char **words, t_scene *scene)
{
	char	**tmp;
	t_point	l_point;
	t_color	l_color;
	if (ft_len_2D(words) != 4 || ft_atof(words[2]) < 0.0 || ft_atof(words[2]) > 1.0)
		ft_error("L Parsing ERROR\n");
	tmp = ft_split(words[1], ',');
	l_point = point(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	double_free(tmp);
	tmp = ft_split(words[3], ',');
	l_color = color(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	check_color(tmp);
	double_free(tmp);
	oadd(&scene->light, object(LIGHT_POINT, 
					light_point(l_point, l_color, ft_atof(words[2]))));
}