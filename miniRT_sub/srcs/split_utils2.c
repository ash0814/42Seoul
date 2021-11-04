/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:28:52 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/23 15:15:45 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(int count, int size)
{
	unsigned char	*r;
	int				i;

	i = -1;
	r = (unsigned char *)malloc(count * size);
	if (r == NULL)
		return (0);
	while (++i < size * count)
		r[i] = 0;
	return ((void *)r);
}

char	**ft_malloc_r(char **r, int h, int len)
{
	int i;
	int j;

	if (r == 0)
		return (0);
	i = -1;
	while (++i < h)
		r[i] = (char *)ft_calloc(sizeof(char), len + 1);
	i = -1;
	while (++i < h)
	{
		if (r[i] == 0)
		{
			j = -1;
			while (r[++j])
				free(r[j]);
			free(r);
			return (0);
		}
	}
	return (r);
}

char	**ft_put_r(const char *s, char c, int h, int len)
{
	int		i;
	int		n;
	int		j;
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

int		ft_split_len(char *s, char c)
{
	int		h;
	int		i;

	if (s == 0)
		return (0);
	h = 0;
	i = -1;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			h++;
	return (h);
}
