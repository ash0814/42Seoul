/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:48:52 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/21 12:04:17 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack *a)
{
	int x;
	int y;
	int z;

	x = a->head->value;
	y = a->head->next->value;
	z = a->head->next->next->value;
	if (x > y && y < z && z > x)
		sa(a);
	else if (x < y && y > z && x > z)
		rra(a);
	else if (x > y && x > z && y < z)
		ra(a);
	else if (y > z)
	{
		if (x > y && x > z)
			ra(a);
		else if (x < y && z > x)
			rra(a);
		sa(a);
	}
	return ;
}

void	check_three_val_b(t_stack *a, t_stack *b, int r)
{
	if (r == 2)
	{
		if (b->head->value < b->head->next->value)
			sb(b);
		pa(a, b);
	}
	pa(a, b);
	return ;
}

void	check_three_val(t_stack *a, int r)
{
	if (a->size == 3)
		three_sort(a);
	else if (r == 2 && a->head->value > a->head->next->value)
		sa(a);
	return ;
}
