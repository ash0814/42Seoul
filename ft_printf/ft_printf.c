/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:23:27 by sehyan            #+#    #+#             */
/*   Updated: 2021/01/26 13:45:04 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	g_flag = 0;
int		g_width = 0;
int		g_prec = 0;
int		g_check_prec = 0;
char	g_format = 0;
int		g_return_count = 0;
int		g_i = 0;

void	ft_set_flag_width(const char *s, va_list ap)
{
	while (s[g_i] == '0' || s[g_i] == '-')
	{
		g_flag = s[g_i];
		if (g_flag == '-')
			break ;
		g_i++;
	}
	while (s[g_i] == '0' || s[g_i] == '-')
		g_i++;
	while (('0' <= s[g_i] && s[g_i] <= '9') || s[g_i] == '*')
	{
		if (s[g_i] == '*')
		{
			g_width = va_arg(ap, int);
			if (g_width < 0)
			{
				g_flag = '-';
				g_width *= -1;
			}
		}
		else
			g_width = g_width * 10 + s[g_i] - '0';
		g_i++;
	}
}

void	ft_set_prec_format(const char *s, va_list ap)
{
	if (s[g_i] == '.' && g_i + 1 < (int)ft_strlen(s))
	{
		g_check_prec = 1;
		g_i++;
		while (('0' <= s[g_i] && s[g_i] <= '9') || s[g_i] == '*')
		{
			if (s[g_i] == '*')
				g_prec = va_arg(ap, int);
			else
				g_prec = g_prec * 10 + s[g_i] - '0';
			g_i++;
		}
	}
	if (s[g_i] == 'c' || s[g_i] == 's' || s[g_i] == 'p' || s[g_i] == 'd'
			|| s[g_i] == 'i' || s[g_i] == 'u' || s[g_i] == 'x'
			|| s[g_i] == 'X' || s[g_i] == '%')
	{
		g_format = s[g_i];
		g_i++;
	}
}

void	ft_check_format(va_list ap)
{
	if (g_format == 'c' || g_format == '%')
		ft_print_c(ap);
	else if (g_format == 'd' || g_format == 'i')
		ft_print_d(ap);
	else if (g_format == 'u')
		ft_print_u(ap);
	else if (g_format == 'x' || g_format == 'X')
		ft_print_x(ap);
	else if (g_format == 'p')
		ft_print_p(ap);
	else if (g_format == 's')
		ft_print_s(ap);
}

int		ft_printf(const char *s, ...)
{
	va_list	ap;

	ft_info_reset_all();
	va_start(ap, s);
	while (g_i < (int)ft_strlen(s))
	{
		if (s[g_i] != '%')
		{
			ft_write_char(s[g_i]);
			g_i++;
		}
		if (s[g_i] == '%')
		{
			g_i++;
			ft_set_flag_width(s, ap);
			ft_set_prec_format(s, ap);
			if (g_format == 0)
				return (-1);
			ft_check_format(ap);
		}
		ft_info_reset();
	}
	va_end(ap);
	return (g_return_count);
}
