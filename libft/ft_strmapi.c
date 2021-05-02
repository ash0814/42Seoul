/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:05:10 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:40:24 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*r;

	i = 0;
	if (s == 0)
		return (0);
	r = (char *)ft_calloc(1, ft_strlen(s) + 1);
	if (r == 0)
		return (0);
	while (s[i])
	{
		r[i] = f(i, s[i]);
		i++;
	}
	return (r);
}
