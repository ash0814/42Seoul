/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:01:52 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/06 14:35:19 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int count;
	int result;

	count = 0;
	result = 1;
	if (power < 0)
		return (0);
	while (count != power)
	{
		result *= nb;
		count++;
	}
	return (result);
}
