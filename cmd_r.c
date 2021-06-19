/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:40:37 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/19 19:24:33 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern int res;

void	ra(t_stack *a)
{
	int top;

	if (a->size < 2)
		return ;
	top = a->head->value;
	pop_head(a);
	push_tail(a, top);
	res++;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int top;

	if (b->size < 2)
		return ;
	top = b->head->value;
	pop_head(b);
	push_tail(b, top);
	res++;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	res--;
	write(1, "rr\n", 3);
}