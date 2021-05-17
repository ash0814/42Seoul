/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:40:46 by ash               #+#    #+#             */
/*   Updated: 2021/05/17 20:57:42 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int			i_atoi(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int m;
	int result;
	int i;

	m = 1;
	result = 0;
	i = i_atoi(str);
	if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * m);
}

double		ft_power(double a, int b)
{
	int i;

	i = 1;
	while (i < b)
	{
		a = a * a;
		i++;
	}
	return (a);
}

double		ft_atof(const char *str)
{
	double m;
	double result;
	int i;
	int j;

	m = 1;
	result = 0;
	i = i_atoi(str);
	if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	j = 0;
	if (str[i] == '.')
	{
		j++;
		i++;
		while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
		{
			result = result + (str[i] - '0') / ft_power(10.0, j);
			i++;
			j++;
		}
	}
	return (result * m);
}