/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:04:53 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/06 14:30:46 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int count;
	int result;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	count = 0;
	result = nb * ft_recursive_power(nb, power - 1);
	return (result);
}
