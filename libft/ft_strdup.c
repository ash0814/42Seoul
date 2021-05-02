/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:11:35 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:36:59 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
