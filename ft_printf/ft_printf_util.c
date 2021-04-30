/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 18:45:08 by sehyan            #+#    #+#             */
/*   Updated: 2021/01/19 21:32:55 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_write_char(char c)
{
	write(1, &c, 1);
	g_return_count++;
}

void	ft_write_str(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		g_return_count++;
		i++;
	}
}

int		ft_put_char(char *s, char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (1);
}

char	*ft_calloc_put(char *s, char c, int len)
{
	int i;

	i = 0;
	if (!(s = (char *)ft_calloc(1, len + 1)))
		return (0);
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (s);
}

void	ft_put_minus(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	s[i - 1] = '-';
}
