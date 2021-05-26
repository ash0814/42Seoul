/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:09:44 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/08 09:19:58 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	unsigned int i;

	i = 1;
	if (nb < 1)
		return (0);
	while (i * i < (unsigned int)nb)
		i++;
	if ((unsigned int)nb == i * i)
		return (i);
	else
		return (0);
}
