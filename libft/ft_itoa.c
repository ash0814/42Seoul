/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:04:59 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 15:43:56 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_result(char *result, long long nb, int count, int f)
{
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
		f = 0;
	}
	while (0 < count)
	{
		result[count - 1] = nb % 10 + '0';
		count--;
		nb = nb / 10;
	}
	if (f == 0)
		result[0] = '-';
	return (result);
}

char		*ft_itoa(int n)
{
	char		*result;
	int			count;
	int			f;
	long long	nb;

	f = 1;
	nb = (long long)n;
	count = 1;
	if (n < 0)
	{
		nb = -n;
		count++;
	}
	while (nb / 10 != 0 && count++)
		nb /= 10;
	result = (char *)ft_calloc(1, count + 1);
	if (result == 0)
		return (0);
	nb = (long long)n;
	ft_result(result, nb, count, f);
	return (result);
}
