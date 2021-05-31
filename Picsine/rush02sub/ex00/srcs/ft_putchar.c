/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:26:18 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/06 13:28:17 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern char		*g_dictname;
extern char		g_buf[1024];
extern int		g_wasspace;
extern int		g_isfirst;
extern int		g_error;

void	ft_putchar(char tc)
{
	if (g_wasspace)
		write(1, " ", 1);
	ft_puttc(tc, 0);
}
