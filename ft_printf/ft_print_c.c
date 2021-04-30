/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:38 by sehyan            #+#    #+#             */
/*   Updated: 2021/01/25 15:52:04 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_set_cpre(void)
{
	char	*cpre;
	int		i;

	i = 0;
	if (g_flag == '-')
	{
		if (!(cpre = (char *)ft_calloc(1, 1)))
			return (0);
	}
	else
	{
		if (!(cpre = (char *)ft_calloc(1, g_width + 1)))
			return (0);
		while (i < g_width - 1)
		{
			if (g_flag == '0')
				cpre[i] = '0';
			else
				cpre[i] = ' ';
			i++;
		}
	}
	return (cpre);
}

char	*ft_set_csur(void)
{
	char	*csur;
	int		i;

	i = 0;
	if (g_flag == '-')
	{
		if (!(csur = (char *)ft_calloc(1, g_width + 1)))
			return (0);
		while (i < g_width - 1)
		{
			csur[i] = ' ';
			i++;
		}
	}
	else
	{
		if (!(csur = (char *)ft_calloc(1, 1)))
			return (0);
	}
	return (csur);
}

void	ft_print_c(va_list ap)
{
	char	*cpre;
	char	*csur;
	char	c;

	if (g_format == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	cpre = ft_set_cpre();
	ft_write_str(cpre);
	ft_write_char(c);
	csur = ft_set_csur();
	ft_write_str(csur);
	free(cpre);
	free(csur);
}
