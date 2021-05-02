/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:45:05 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:41:07 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s || start >= ft_strlen(s) || ft_strlen(s) < start + len)
	{
		subs = (char *)malloc(1);
		if (subs == 0)
			return (0);
		subs[0] = 0;
		return (subs);
	}
	subs = (char *)ft_calloc(sizeof(char), len + 1);
	if (subs == 0 || s == 0)
		return (0);
	i = 0;
	while (i < len && s[start] != 0)
	{
		subs[i] = (char)s[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	return ((char *)subs);
}
