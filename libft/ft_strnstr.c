/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:23:23 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:38:14 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*p1;
	const char	*p2;
	size_t		l;

	if (*needle == 0)
		return ((char *)haystack);
	l = (size_t)haystack + len;
	while (*haystack != 0 && (size_t)haystack < l)
	{
		if (*haystack == *needle)
		{
			p1 = haystack;
			p2 = needle;
			while (*++p1 == *++p2 && *p1 != 0 && *p2 != 0 && (size_t)p1 < l)
				;
			if (*p2 == 0)
				return ((char *)haystack);
			if (*p1 == 0)
				break ;
		}
		haystack++;
	}
	return (0);
}
