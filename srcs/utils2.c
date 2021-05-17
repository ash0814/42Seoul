/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:30:26 by ash               #+#    #+#             */
/*   Updated: 2021/05/18 00:32:19 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void    check_zero_to_one(char **tmp)
{
    if (ft_atof(tmp[0]) > 1.0 || ft_atof(tmp[0]) < 0.0 ||
    ft_atof(tmp[1]) > 1.0 || ft_atof(tmp[1]) < 0.0 ||
    ft_atof(tmp[2]) > 1.0 || ft_atof(tmp[2]) < 0.0)
    ft_error("parsing value is not in 0 ~ 1\n");
}

void    check_three_double(char **tmp)
{
    if (ft_atof(tmp[0]) > 255.0 || ft_atof(tmp[0]) < 0.0 ||
        ft_atof(tmp[1]) > 255.0 || ft_atof(tmp[1]) < 0.0 ||
        ft_atof(tmp[2]) > 255.0 || ft_atof(tmp[2]) < 0.0)
        ft_error("parsing value is not in 0 ~ 255\n");
}

void    check_three_nor(char **tmp)
{
    if (ft_atof(tmp[0]) > 1.0 || ft_atof(tmp[0]) < -1.0 ||
    ft_atof(tmp[1]) > 1.0 || ft_atof(tmp[1]) < -1.0 ||
    ft_atof(tmp[2]) > 1.0 || ft_atof(tmp[2]) < -1.0)
    ft_error("parsing value is not in -1 ~ 1\n");
}