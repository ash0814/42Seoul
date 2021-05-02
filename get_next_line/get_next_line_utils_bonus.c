/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:34:49 by sehyan            #+#    #+#             */
/*   Updated: 2021/03/29 12:31:01 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (0);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	s[i] = 0;
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
	{
		str[j] = s1[i];
		j++;
	}
	free(s1);
	i = -1;
	while (s2[++i])
	{
		str[j] = s2[i];
		j++;
	}
	str[j] = 0;
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int idx;

	idx = 0;
	if (!s)
		return (0);
	while (s[idx] != '\0')
		idx++;
	return (idx);
}
