/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:59:57 by sehyan            #+#    #+#             */
/*   Updated: 2020/11/26 14:49:20 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int temp[size];
	int i;

	i = 0;
	while (i < size)
	{
		temp[i++] = tab[size - 1 - i];
	}
	i = 0;
	while (i < size)
	{
		tab[i++] = temp[i];
	}
}
