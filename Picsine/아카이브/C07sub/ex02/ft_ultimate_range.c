/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:48:11 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/08 16:26:37 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimaie_range(int **range, int min, int max)
{
	int l;
	int i;

	i = 0;
	if (min >= max)
		return (0);
	l = max - min;
	range = (int *)malloc(sizeof(int) * l);
	if (range == 0)
		return (-1);
	while (i < l)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (l);
}
