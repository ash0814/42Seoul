/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:04:48 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:42:03 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_malloc_r(char **r, size_t h, size_t len)
{
	size_t i;
	size_t j;

	if (r == 0)
		return (0);
	i = -1;
	while (++i < h)
		r[i] = (char *)ft_calloc(sizeof(char), len + 1);
	i = -1;
	while (i < h)
		if (r[i] == 0)
		{
			j = -1;
			while (r[++j])
				free(r[j]);
			free(r);
			return (0);
		}
	return (r);
}

static char		**ft_put_r(const char *s, char c, size_t h, size_t len)
{
	size_t	i;
	size_t	n;
	size_t	j;
	char	**r;

	i = -1;
	n = 0;
	r = (char **)ft_calloc(sizeof(char *), h + 1);
	if (ft_malloc_r(r, h, len) == 0)
		return (0);
	while (++i < h)
	{
		while (s[n] == c && s[n])
			n++;
		j = -1;
		while (s[n] != c && s[n] && ++j < len)
		{
			r[i][j] = s[n];
			n++;
		}
	}
	return (r);
}

static size_t	ft_check_len(char const *s, char c)
{
	size_t i;
	size_t len;
	size_t n;

	n = 0;
	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] == c)
			n = 0;
		if (s[i] != c)
			n++;
		if (n > len)
			len = n;
	}
	return (len);
}

char			**ft_split(char const *s, char c)
{
	char	**r;
	size_t	len;
	size_t	h;
	size_t	i;

	if (s == 0)
		return (0);
	h = 0;
	i = -1;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			h++;
	len = ft_check_len(s, c);
	r = ft_put_r(s, c, h, len);
	if (r == 0)
		return (0);
	return (r);
}
