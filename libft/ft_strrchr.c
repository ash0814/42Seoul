/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:11:10 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:37:59 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *r;

	r = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			r = s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	if (r == 0)
		return (0);
	return ((char *)r);
}
