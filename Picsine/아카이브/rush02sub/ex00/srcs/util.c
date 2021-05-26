/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:13:46 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/06 12:59:10 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern char		*g_dictname;
extern char		g_buf[1024];
extern int		g_wasspace;
extern int		g_isfirst;
extern int		g_error;

int		ft_is_valid(char *str)
{
	int		i;

	if (!*str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	print_dict_err(void)
{
	write(1, "Dict Error", 10);
}

int		ft_clear_buf(void)
{
	int i;

	i = 0;
	while (i < 1024)
		g_buf[i++] = 0;
	return (1);
}

void	ft_puttc(char tc, int ws)
{
	g_wasspace = ws;
	write(1, &tc, 1);
}

void	ft_make_zero(int *i1, int *i2)
{
	*i1 = 0;
	*i2 = 0;
}
