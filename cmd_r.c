/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:40:37 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/20 18:24:51 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern int res;

int		ra(t_stack *a)
{
	int top;

	if (a->size < 2)
		return (0);
	top = a->head->value;
	pop_head(a);
	push_tail(a, top);
	res++;
	write(1, "ra\n", 3);
	return (1);
}

int		rb(t_stack *b)
{
	int top;

	if (b->size < 2)
		return (0);
	top = b->head->value;
	pop_head(b);
	push_tail(b, top);
	res++;
	write(1, "rb\n", 3);
	return (1);
}

int		rr(t_stack *a, t_stack *b)
{
	int x;
	int y;

	x = ra(a);
	y = rb(b);
	res--;
	write(1, "rr\n", 3);
	if (x + y > 0)
		return (1);
	return (0);
}