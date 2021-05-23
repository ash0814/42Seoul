/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:30:26 by ash               #+#    #+#             */
/*   Updated: 2021/05/23 15:29:31 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	check_zero_to_one(char **tmp)
{
	if (!tmp || ft_atof(tmp[0]) > 1.0 || ft_atof(tmp[0]) < 0.0 ||
		ft_atof(tmp[1]) > 1.0 || ft_atof(tmp[1]) < 0.0 ||
		ft_atof(tmp[2]) > 1.0 || ft_atof(tmp[2]) < 0.0)
		ft_error("parsing value is not in 0 ~ 1\n");
}

void	check_color(char **tmp)
{
	if (!tmp || ft_atof(tmp[0]) > 255.0 || ft_atof(tmp[0]) < 0.0 ||
		ft_atof(tmp[1]) > 255.0 || ft_atof(tmp[1]) < 0.0 ||
		ft_atof(tmp[2]) > 255.0 || ft_atof(tmp[2]) < 0.0)
		ft_error("parsing value is not in 0 ~ 255\n");
}

void	check_three_nor(char **tmp)
{
	if (!tmp || ft_atof(tmp[0]) > 1.0 || ft_atof(tmp[0]) < -1.0 ||
		ft_atof(tmp[1]) > 1.0 || ft_atof(tmp[1]) < -1.0 ||
		ft_atof(tmp[2]) > 1.0 || ft_atof(tmp[2]) < -1.0)
		ft_error("parsing value is not in -1 ~ 1\n");
}
