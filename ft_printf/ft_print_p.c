/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:58:36 by sehyan            #+#    #+#             */
/*   Updated: 2021/01/27 20:27:47 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_set_ppre(unsigned long long u, int plen)
{
	char	*ppre;

	ppre = 0;
	if (!(ppre = ft_set_check_ppre(u, ppre, plen)))
		return (0);
	if (g_prec == 0 && g_check_prec == 1 && u == 0
			&& g_width >= plen && g_flag != '-')
		return (ppre = (char *)ft_calloc_put(ppre, ' ', g_width - plen));
	return (ppre);
}

char	*ft_set_check_ppre(unsigned long long u, char *ppre, int plen)
{
	if (g_flag == '-' || (g_prec < 0 && g_width <= plen) ||
			(g_prec == 0 && (g_width <= plen || (g_check_prec == 1 && u == 0)))
			|| (plen >= g_width && plen >= g_prec))
		ppre = (char *)ft_calloc(1, 3);
	else if ((g_prec <= 0 && g_width > plen))
	{
		if (!(ppre = (char *)ft_calloc(1, g_width - plen + 1)))
			return (0);
		if (g_flag != '0' || (g_prec == 0 && g_check_prec == 1))
			ft_put_char(ppre, ' ', g_width - plen);
		else
			ft_put_char(ppre, '0', g_width - plen);
	}
	else if (g_width >= g_prec && g_prec >= plen)
		ppre = ft_calloc_put(ppre, ' ', g_width - g_prec);
	else if (g_width >= plen && plen >= g_prec)
		ppre = ft_calloc_put(ppre, ' ', g_width - plen);
	else
		ppre = ft_calloc_put(ppre, '0', g_prec - plen);
	return (ppre);
}

char	*ft_set_pstr(unsigned long long u, int plen)
{
	char	*pstr;
	char	*strx;

	strx = ft_hexa_ptr(u);
	pstr = 0;
	if (g_width >= g_prec && g_prec >= plen)
	{
		if (!(pstr = (char *)ft_calloc(1, g_prec + 1)))
			return (0);
		ft_put_char(pstr, '0', g_prec - plen);
		ft_strlcat(pstr, strx, g_prec + 1);
	}
	else
		pstr = strx;
	return (pstr);
}

char	*ft_set_psur(unsigned long long u, int plen)
{
	char	*psur;

	psur = 0;
	if (g_flag != '-' || (g_prec < 0 && g_width <= plen)
			|| (plen >= g_width && plen >= g_prec))
		return (psur = (char *)ft_calloc(1, 1));
	else if (g_prec == 0 && g_check_prec == 1 && u == 0
			&& g_width >= plen && g_flag == '-')
		return (psur = (char *)ft_calloc_put(psur, ' ', g_width - 2));
	else if ((g_prec <= 0 && g_width > plen))
		return (psur = ft_calloc_put(psur, ' ', g_width - plen));
	else if (g_width >= g_prec && g_prec >= plen)
	{
		if (u < 0)
			g_prec += 1;
		if (!(psur = ft_calloc_put(psur, ' ', g_width - g_prec)))
			return (0);
	}
	else
		return (psur = ft_calloc_put(psur, ' ', g_width - plen));
	return (psur);
}

void	ft_print_p(va_list ap)
{
	char				*ppre;
	char				*pstr;
	char				*psur;
	unsigned long long	u;
	char				*strp;

	u = va_arg(ap, unsigned long long);
	strp = ft_hexa_ptr(u);
	if (g_flag == '-' && g_prec >= (int)ft_strlen(strp) &&
			((int)ft_strlen(strp) >= g_width || g_prec >= g_width))
		g_flag = '0';
	if (g_prec > g_width)
		ft_write_str("0x");
	ppre = ft_set_ppre(u, (int)ft_strlen(strp));
	ft_write_str(ppre);
	pstr = ft_set_pstr(u, (int)ft_strlen(strp));
	ft_write_str(pstr);
	psur = ft_set_psur(u, (int)ft_strlen(strp));
	ft_write_str(psur);
	free(strp);
	free(ppre);
	free(pstr);
	free(psur);
}
