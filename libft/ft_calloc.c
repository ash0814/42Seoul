/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:11:24 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:29:35 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*r;
	size_t			i;

	i = -1;
	r = (unsigned char *)malloc(count * size);
	if (r == NULL)
		return (0);
	while (++i < size * count)
		r[i] = 0;
	return ((void *)r);
}
