/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:40:16 by sehyan            #+#    #+#             */
/*   Updated: 2021/01/26 14:36:44 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_set_spre(int slen)
{
	char	*spre;

	if (g_width > slen && g_flag != '-')
	{
		if (!(spre = (char *)ft_calloc(1, g_width - slen + 1)))
			return (0);
		if (g_flag == '0')
			ft_put_char(spre, '0', g_width - slen);
		else
			ft_put_char(spre, ' ', g_width - slen);
	}
	else if (!(spre = (char *)ft_calloc(1, 1)))
		return (0);
	return (spre);
}

char	*ft_set_sstr(char *s)
{
	char	*sstr;

	sstr = 0;
	if (s == 0)
	{
		if (!(sstr = (char *)ft_calloc(1, 7)))
			return (0);
		if (0 < g_prec)
			ft_strlcpy(sstr, "(null)", g_prec + 1);
		else if (g_check_prec == 1 && g_prec == 0)
			return (sstr);
		else
			sstr = "(null)";
		return (sstr);
	}
	if (g_check_prec == 1 && g_prec >= 0)
	{
		if (!(sstr = (char *)ft_calloc(1, g_prec + 1)))
			return (0);
		ft_strlcpy(sstr, s, g_prec + 1);
	}
	else
		return (s);
	return (sstr);
}

char	*ft_set_ssur(int slen)
{
	char	*ssur;

	if (g_width > slen && g_flag == '-')
	{
		if (!(ssur = (char *)ft_calloc(1, g_width - slen + 1)))
			return (0);
		ft_put_char(ssur, ' ', g_width - slen);
	}
	else if (!(ssur = (char *)ft_calloc(1, 1)))
		return (0);
	return (ssur);
}

void	ft_print_s(va_list ap)
{
	char	*spre;
	char	*sstr;
	char	*ssur;
	char	*s;
	int		slen;

	s = va_arg(ap, char *);
	sstr = ft_set_sstr(s);
	if (sstr == 0)
		slen = 0;
	else
		slen = (int)ft_strlen(sstr);
	spre = ft_set_spre(slen);
	ssur = ft_set_ssur(slen);
	ft_write_str(spre);
	ft_write_str(sstr);
	ft_write_str(ssur);
	free(spre);
	free(ssur);
}
