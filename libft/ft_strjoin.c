/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:04:26 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:41:21 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (0);
	str = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == 0)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
	{
		str[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i])
	{
		str[j] = s2[i];
		j++;
	}
	str[j] = 0;
	return (str);
}
