/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:04:05 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/08 15:47:46 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int l;
	int *arr;
	int i;

	if (min >= max)
		return (0);
	l = max - min;
	arr = (int *)malloc(sizeof(int) * l);
	i = 0;
	while (i < l)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
