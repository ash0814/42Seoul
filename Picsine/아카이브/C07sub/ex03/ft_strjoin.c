/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:27:09 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/10 14:50:51 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char				*ft_strcpy(char *dest, char *src)
{
	unsigned int	size;

	size = 0;
	while (src[size])
	{
		*dest = src[size++];
		dest++;
	}
	return (dest);
}

int					ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

unsigned int		ft_gettotalsize(int size, char **strs, char *sep)
{
	unsigned int	totalsize;
	int				i;

	totalsize = 0;
	i = 0;
	while (i < size)
		totalsize += (unsigned int)ft_strlen(strs[i++]);
	totalsize += (size - 1) * ft_strlen(sep);
	return (totalsize);
}

char				*ft_strjoin(int size, char **strs, char *sep)
{
	unsigned int	totalsize;
	int				i;
	char			*v;
	char			*s;

	totalsize = ft_gettotalsize(size, strs, sep);
	if (size == 0 || !(v = (char *)malloc(totalsize + 1)))
	{
		v = (char *)malloc(sizeof(char));
		*v = 0;
		if (size == 0)
			return (v);
	}
	i = 0;
	s = v;
	while (i < size)
	{
		v = ft_strcpy(v, strs[i]);
		if (!(i == size - 1))
			v = ft_strcpy(v, sep);
		i++;
	}
	*v = 0;
	return (s);
}
