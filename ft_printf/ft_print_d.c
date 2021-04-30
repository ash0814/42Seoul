/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:40:15 by sehyan            #+#    #+#             */
/*   Updated: 2021/01/25 21:46:20 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_set_dpre(int d, int dlen)
{
	char	*dpre;

	dpre = 0;
	if (!(dpre = ft_set_check_dpre(d, dpre, dlen)))
		return (0);
	if (d < 0 && (dpre[0] == '0' || dpre[0] == '\0') && d != -2147483648)
		dpre[0] = '-';
	else if (d < 0 && d != -2147483648)
		ft_put_minus(dpre);
	return (dpre);
}

char	*ft_set_check_dpre(int d, char *dpre, int dlen)
{
	if (g_flag == '-' || (g_prec < 0 && g_width <= dlen) ||
			(g_prec == 0 && (g_width <= dlen || (g_check_prec == 1 && d == 0)))
			|| (dlen >= g_width && dlen >= g_prec))
		dpre = (char *)ft_calloc(1, 2);
	else if ((g_prec <= 0 && g_width > dlen))
	{
		if (!(dpre = (char *)ft_calloc(1, g_width - dlen + 1)))
			return (0);
		if (g_flag != '0' || (g_prec == 0 && g_check_prec == 1))
			ft_put_char(dpre, ' ', g_width - dlen);
		else
			ft_put_char(dpre, '0', g_width - dlen);
	}
	else if (g_width >= g_prec && g_prec >= dlen)
		dpre = ft_calloc_put(dpre, ' ', g_width - g_prec);
	else if (g_width >= dlen && dlen >= g_prec)
		dpre = ft_calloc_put(dpre, ' ', g_width - dlen);
	else
		dpre = ft_calloc_put(dpre, '0', g_prec - dlen);
	return (dpre);
}

char	*ft_set_dstr(int d, int dlen)
{
	char	*dstr;
	char	*strd;

	if (d < 0)
		d *= -1;
	strd = ft_itoa(d);
	dstr = 0;
	if (g_prec == 0 && g_check_prec == 1 && d == 0 && g_width >= 0)
		return (dstr = (char *)ft_calloc_put(dstr, ' ', g_width));
	else if (g_width >= g_prec && g_prec >= dlen)
	{
		if (!(dstr = (char *)ft_calloc(1, g_prec + 1)))
			return (0);
		ft_put_char(dstr, '0', g_prec - dlen);
		ft_strlcat(dstr, strd, g_prec + 1);
	}
	else
		dstr = strd;
	return (dstr);
}

char	*ft_set_dsur(int d, int dlen)
{
	char	*dsur;

	if (d < 0)
		dlen += 1;
	dsur = 0;
	if (g_flag != '-' || (g_prec < 0 && g_width <= dlen) ||
			(g_prec == 0 && (g_width <= dlen || (g_check_prec == 1 && d == 0)))
			|| (dlen >= g_width && dlen >= g_prec))
		return (dsur = (char *)ft_calloc(1, 1));
	else if ((g_prec <= 0 && g_width > dlen))
		return (dsur = ft_calloc_put(dsur, ' ', g_width - dlen));
	else if (g_width >= g_prec && g_prec >= dlen)
	{
		if (d < 0)
			g_prec += 1;
		if (!(dsur = ft_calloc_put(dsur, ' ', g_width - g_prec)))
			return (0);
	}
	else
		return (dsur = ft_calloc_put(dsur, ' ', g_width - dlen));
	return (dsur);
}

void	ft_print_d(va_list ap)
{
	char	*dpre;
	char	*dstr;
	char	*dsur;
	int		d;
	int		dlen;

	d = va_arg(ap, int);
	if (d >= 0)
		dlen = ft_strlen(ft_itoa(d));
	else
		dlen = ft_strlen(ft_itoa(-d));
	if (d < 0 && g_prec >= g_width)
		g_prec += 1;
	if (g_flag == '-' && g_prec >= dlen &&
			((int)ft_strlen(ft_itoa(d)) >= g_width || g_prec >= g_width))
		g_flag = '0';
	dpre = ft_set_dpre(d, dlen);
	ft_write_str(dpre);
	dstr = ft_set_dstr(d, dlen);
	ft_write_str(dstr);
	dsur = ft_set_dsur(d, dlen);
	ft_write_str(dsur);
	free(dpre);
	free(dstr);
	free(dsur);
}
