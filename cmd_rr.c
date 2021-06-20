/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:41:38 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/20 18:25:40 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern int res;

int		rra(t_stack *a)
{
	int	a_last;

	if (a->size < 2)
		return (0);
	a_last = a->tail->value;
	pop_tail(a);
	push_head(a, a_last);
	res++;
	write(1, "rra\n", 4);
	return (1);
}

int		rrb(t_stack *b)
{
	int	b_last;

	if (b->size < 2)
		return (0);
	b_last = b->tail->value;
	pop_tail(b);
	push_head(b, b_last);
	res++;
	write(1, "rrb\n", 4);
	return (1);
}

int		rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	res--;
	write(1, "rrr\n", 4);
	return (1);
}