/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:41:38 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/19 14:37:53 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	int	a_last;

	if (a->size < 2)
		return ;
	a_last = a->tail->value;
	pop_tail(a);
	push_head(a, a_last);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	int	b_last;

	if (b->size < 2)
		return ;
	b_last = b->tail->value;
	pop_tail(b);
	push_head(b, b_last);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}