/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 21:50:49 by sehyan            #+#    #+#             */
/*   Updated: 2021/01/19 22:42:33 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_set_upre(unsigned int u, int ulen)
{
	char	*upre;

	upre = 0;
	if (!(upre = ft_set_check_upre(u, upre, ulen)))
		return (0);
	return (upre);
}

char	*ft_set_check_upre(unsigned int u, char *upre, int ulen)
{
	if (g_flag == '-' || (g_prec < 0 && g_width <= ulen) ||
			(g_prec == 0 && (g_width <= ulen || (g_check_prec == 1 && u == 0)))
			|| (ulen >= g_width && ulen >= g_prec))
		upre = (char *)ft_calloc(1, 2);
	else if ((g_prec <= 0 && g_width > ulen))
	{
		if (!(upre = (char *)ft_calloc(1, g_width - ulen + 1)))
			return (0);
		if (g_flag != '0' || (g_prec == 0 && g_check_prec == 1))
			ft_put_char(upre, ' ', g_width - ulen);
		else
			ft_put_char(upre, '0', g_width - ulen);
	}
	else if (g_width >= g_prec && g_prec >= ulen)
		upre = ft_calloc_put(upre, ' ', g_width - g_prec);
	else if (g_width >= ulen && ulen >= g_prec)
		upre = ft_calloc_put(upre, ' ', g_width - ulen);
	else
		upre = ft_calloc_put(upre, '0', g_prec - ulen);
	return (upre);
}

char	*ft_set_ustr(unsigned int u, int ulen)
{
	char	*ustr;
	char	*stru;

	stru = ft_itoa(u);
	ustr = 0;
	if (g_prec == 0 && g_check_prec == 1 && u == 0 && g_width >= 0)
		return (ustr = (char *)ft_calloc_put(ustr, ' ', g_width));
	else if (g_width >= g_prec && g_prec >= ulen)
	{
		if (!(ustr = (char *)ft_calloc(1, g_prec + 1)))
			return (0);
		ft_put_char(ustr, '0', g_prec - ulen);
		ft_strlcat(ustr, stru, g_prec + 1);
	}
	else
		ustr = stru;
	return (ustr);
}

char	*ft_set_usur(unsigned int u, int ulen)
{
	char	*usur;

	usur = 0;
	if (g_flag != '-' || (g_prec < 0 && g_width <= ulen) ||
			(g_prec == 0 && (g_width <= ulen || (g_check_prec == 1 && u == 0)))
			|| (ulen >= g_width && ulen >= g_prec))
		return (usur = (char *)ft_calloc(1, 1));
	else if ((g_prec <= 0 && g_width > ulen))
		return (usur = ft_calloc_put(usur, ' ', g_width - ulen));
	else if (g_width >= g_prec && g_prec >= ulen)
	{
		if (u < 0)
			g_prec += 1;
		if (!(usur = ft_calloc_put(usur, ' ', g_width - g_prec)))
			return (0);
	}
	else
		return (usur = ft_calloc_put(usur, ' ', g_width - ulen));
	return (usur);
}

void	ft_print_u(va_list ap)
{
	char				*upre;
	char				*ustr;
	char				*usur;
	unsigned int		u;
	int					ulen;

	u = va_arg(ap, unsigned int);
	ulen = ft_strlen(ft_itoa(u));
	if (g_flag == '-' && g_prec >= ulen &&
			((int)ft_strlen(ft_itoa(u)) >= g_width || g_prec >= g_width))
		g_flag = '0';
	upre = ft_set_upre(u, ulen);
	ft_write_str(upre);
	ustr = ft_set_ustr(u, ulen);
	ft_write_str(ustr);
	usur = ft_set_usur(u, ulen);
	ft_write_str(usur);
	free(upre);
	free(ustr);
	free(usur);
}
