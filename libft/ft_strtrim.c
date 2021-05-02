/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:04:37 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:44:13 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_f(const char *s1, const char *set)
{
	size_t	f;
	size_t	i;

	i = -1;
	f = 0;
	while (++i != ft_strlen(set))
		if (s1[f] == set[i])
		{
			f++;
			i = -1;
		}
	return (f);
}

static size_t	ft_check_b(char const *s1, char const *set)
{
	size_t	b;
	size_t	i;

	i = -1;
	b = ft_strlen(s1) - 1;
	while (++i != ft_strlen(set))
		if (s1[b] == set[i])
		{
			b--;
			i = -1;
		}
	return (b);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	size_t	f;
	size_t	b;
	size_t	i;
	size_t	rl;

	if (s1 == 0)
		return (0);
	f = ft_check_f(s1, set);
	if (f == ft_strlen(s1))
		return (r = (char *)ft_calloc(sizeof(char), 1));
	b = ft_check_b(s1, set);
	rl = b - f + 1;
	r = (char *)ft_calloc(sizeof(char), rl + 1);
	if (r == 0)
		return (0);
	i = -1;
	while (++i < rl)
	{
		r[i] = s1[f];
		f++;
	}
	return (r);
}
