/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:03:51 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:36:08 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = -1;
	if (dst == NULL && src == NULL)
		return (0);
	if (d < s)
	{
		while (++i < len)
			d[i] = s[i];
	}
	else if (d >= s)
	{
		len += 1;
		while (--len > 0)
			d[len - 1] = s[len - 1];
	}
	return (dst);
}
