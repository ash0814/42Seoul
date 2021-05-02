/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:47:40 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:37:09 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t sl;
	size_t dl;

	sl = ft_strlen(src);
	dl = ft_strlen(dst);
	if (dstsize == 0)
		return (sl);
	if (dstsize < dl)
		return (sl + dstsize);
	i = 0;
	while (i + dl + 1 < dstsize && src[i])
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = 0;
	return (dl + sl);
}
