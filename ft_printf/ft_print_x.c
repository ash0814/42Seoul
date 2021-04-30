/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:56:48 by sehyan            #+#    #+#             */
/*   Updated: 2021/01/25 15:27:34 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_set_xpre(unsigned int u, int xlen)
{
	char	*xpre;

	xpre = 0;
	if (!(xpre = ft_set_check_xpre(u, xpre, xlen)))
		return (0);
	return (xpre);
}

char	*ft_set_check_xpre(unsigned int u, char *xpre, int xlen)
{
	if (g_flag == '-' || (g_prec < 0 && g_width <= xlen) ||
			(g_prec == 0 && (g_width <= xlen || (g_check_prec == 1 && u == 0)))
			|| (xlen >= g_width && xlen >= g_prec))
		xpre = (char *)ft_calloc(1, 1);
	else if ((g_prec <= 0 && g_width > xlen))
	{
		if (!(xpre = (char *)ft_calloc(1, g_width - xlen + 1)))
			return (0);
		if (g_flag != '0' || (g_prec == 0 && g_check_prec == 1))
			ft_put_char(xpre, ' ', g_width - xlen);
		else
			ft_put_char(xpre, '0', g_width - xlen);
	}
	else if (g_width >= g_prec && g_prec >= xlen)
		xpre = ft_calloc_put(xpre, ' ', g_width - g_prec);
	else if (g_width >= xlen && xlen >= g_prec)
		xpre = ft_calloc_put(xpre, ' ', g_width - xlen);
	else
		xpre = ft_calloc_put(xpre, '0', g_prec - xlen);
	return (xpre);
}

char	*ft_set_xstr(unsigned int u, int xlen)
{
	char	*xstr;
	char	*strx;

	strx = ft_hexa(u);
	xstr = 0;
	if (g_prec == 0 && g_check_prec == 1 && u == 0 && g_width >= 0)
		return (xstr = (char *)ft_calloc_put(xstr, ' ', g_width));
	else if (g_width >= g_prec && g_prec >= xlen)
	{
		if (!(xstr = (char *)ft_calloc(1, g_prec + 1)))
			return (0);
		ft_put_char(xstr, '0', g_prec - xlen);
		ft_strlcat(xstr, strx, g_prec + 1);
	}
	else
		xstr = strx;
	return (xstr);
}

char	*ft_set_xsur(unsigned int u, int xlen)
{
	char	*xsur;

	xsur = 0;
	if (g_flag != '-' || (g_prec < 0 && g_width <= xlen) ||
			(g_prec == 0 && (g_width <= xlen || (g_check_prec == 1 && u == 0)))
			|| (xlen >= g_width && xlen >= g_prec))
		return (xsur = (char *)ft_calloc(1, 1));
	else if ((g_prec <= 0 && g_width > xlen))
		return (xsur = ft_calloc_put(xsur, ' ', g_width - xlen));
	else if (g_width >= g_prec && g_prec >= xlen)
	{
		if (u < 0)
			g_prec += 1;
		if (!(xsur = ft_calloc_put(xsur, ' ', g_width - g_prec)))
			return (0);
	}
	else
		return (xsur = ft_calloc_put(xsur, ' ', g_width - xlen));
	return (xsur);
}

void	ft_print_x(va_list ap)
{
	char				*xpre;
	char				*xstr;
	char				*xsur;
	unsigned int		u;
	int					xlen;

	u = va_arg(ap, unsigned int);
	xlen = ft_strlen(ft_hexa(u));
	if (g_flag == '-' && g_prec >= xlen &&
			((int)ft_strlen(ft_hexa(u)) >= g_width || g_prec >= g_width))
		g_flag = '0';
	xpre = ft_set_xpre(u, xlen);
	ft_write_str(xpre);
	xstr = ft_set_xstr(u, xlen);
	ft_write_str(xstr);
	xsur = ft_set_xsur(u, xlen);
	ft_write_str(xsur);
	free(xpre);
	free(xstr);
	free(xsur);
}
