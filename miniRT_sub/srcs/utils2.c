/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:30:26 by ash               #+#    #+#             */
/*   Updated: 2021/05/27 10:28:35 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	check_zero_to_one(char **tmp)
{
	if (len_spl(tmp) != 3)
		ft_error("point, color, vec don't have 3 value\n");
	if (!tmp || ft_atof(tmp[0]) > 1.0 || ft_atof(tmp[0]) < 0.0 ||
		ft_atof(tmp[1]) > 1.0 || ft_atof(tmp[1]) < 0.0 ||
		ft_atof(tmp[2]) > 1.0 || ft_atof(tmp[2]) < 0.0)
		ft_error("parsing value is not in 0 ~ 1\n");
}

void	check_color(char **tmp)
{
	if (len_spl(tmp) != 3)
		ft_error("point, color, vec don't have 3 value\n");
	if (!tmp || ft_atof(tmp[0]) > 255.0 || ft_atof(tmp[0]) < 0.0 ||
		ft_atof(tmp[1]) > 255.0 || ft_atof(tmp[1]) < 0.0 ||
		ft_atof(tmp[2]) > 255.0 || ft_atof(tmp[2]) < 0.0)
		ft_error("parsing value is not in 0 ~ 255\n");
}

void	check_three_nor(char **tmp)
{
	if (len_spl(tmp) != 3)
		ft_error("point, color, vec don't have 3 value\n");
	if (!tmp || ft_atof(tmp[0]) > 1.0 || ft_atof(tmp[0]) < -1.0 ||
		ft_atof(tmp[1]) > 1.0 || ft_atof(tmp[1]) < -1.0 ||
		ft_atof(tmp[2]) > 1.0 || ft_atof(tmp[2]) < -1.0)
		ft_error("parsing value is not in -1 ~ 1\n");
}
