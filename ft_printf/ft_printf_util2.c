/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 21:38:15 by sehyan            #+#    #+#             */
/*   Updated: 2021/01/26 14:19:54 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_info_reset_all(void)
{
	g_flag = 0;
	g_width = 0;
	g_prec = 0;
	g_check_prec = 0;
	g_format = 0;
	g_return_count = 0;
	g_i = 0;
}

void	ft_info_reset(void)
{
	g_flag = 0;
	g_width = 0;
	g_prec = 0;
	g_check_prec = 0;
	g_format = 0;
}

char	*ft_hexa(unsigned int n)
{
	char	*h;
	int		i;

	h = (char *)ft_calloc(1, 11);
	i = 0;
	if (n == 0)
		h[i] = '0';
	while (n != 0)
	{
		if (g_format == 'x')
			h[i] = "0123456789abcdef"[n % 16];
		else
			h[i] = "0123456789ABCDEF"[n % 16];
		n = n / 16;
		i++;
	}
	ft_rev(h, (int)ft_strlen(h));
	return (h);
}

char	*ft_hexa_ptr(unsigned long long u)
{
	char	*pre;
	char	*hex;
	int		i;

	hex = (char *)ft_calloc(1, 20);
	i = -1;
	if (u == 0 && g_prec == 0 && g_check_prec == 1)
		hex = (char *)ft_calloc(1, 1);
	else if (u == 0)
		hex[0] = '0';
	while (u != 0)
	{
		hex[++i] = "0123456789abcdef"[u % 16];
		u = u / 16;
	}
	ft_rev(hex, (int)ft_strlen(hex));
	if (!(pre = (char *)ft_calloc(1, (int)ft_strlen(hex) + 2)))
		return (0);
	if (g_prec <= g_width)
	{
		pre[0] = '0';
		pre[1] = 'x';
	}
	ft_strlcat(pre, hex, (int)ft_strlen(hex) + 3);
	return (pre);
}

void	ft_rev(char *s, int len)
{
	char	temp[len];
	int		i;

	i = -1;
	while (++i < len)
		temp[i] = s[len - 1 - i];
	i = -1;
	while (++i < len)
		s[i] = temp[i];
}
