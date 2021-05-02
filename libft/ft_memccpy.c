/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:33:49 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:30:28 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (d == NULL && s == NULL)
		return (0);
	while (s[i] != (unsigned char)c && i < n)
	{
		d[i] = s[i];
		i++;
	}
	if (i == n)
		return (0);
	d[i] = s[i];
	return (&dst[i + 1]);
}
