/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:26:28 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/18 12:39:23 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"


int		ft_check_len(char const *s, char c)
{
	int		i;
	int		len;
	int		n;

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

char	**ft_split(char const *s, char c)
{
	char	**r;
	int		len;
	int		h;
	int		i;

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
	{
		return (0);
	}
	return (r);
}

char	**ft_put_r_wsp(const char *s, int h, int len)
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
		while (((9 <= s[n] && s[n] <= 13) || s[n] == 32) && s[n])
			n++;
		j = -1;
		while ((!(9 <= s[n] && s[n] <= 13) && s[n] != 32) && s[n] && ++j < len)
		{
			r[i][j] = s[n];
			n++;
		}
	}
	return (r);
}

int	ft_check_len_wsp(char const *s)
{
	int		i;
	int		len;
	int		n;

	n = 0;
	i = -1;
	len = 0;
	while (s[++i])
	{
		if ((9 <= s[i] && s[i] <= 13) || s[i] == 32)
			n = 0;
		if (!(9 <= s[i] && s[i] <= 13) && s[i] != 32)
			n++;
		if (n > len)
			len = n;
	}
	return (len);
}

char	**ft_split_wsp(char const *s)
{
	char	**r;
	int		len;
	int		h;
	int		i;

	if (s == 0)
		return (0);
	h = 0;
	i = -1;
	while (s[++i])
	{
		if (!(9 <= s[i] && s[i] <= 13) && s[i] != ' ' 
			&& ((9 <= s[i + 1] && s[i + 1] <= 13)
			|| s[i + 1] == 32 || s[i + 1] == 0))
			h++;
	}
	len = ft_check_len_wsp(s);
	r = ft_put_r_wsp(s, h, len);
	if (r == 0)
		return (0);
	return (r);
}
