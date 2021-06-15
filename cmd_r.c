/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:40:37 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/15 12:43:49 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int top;

	top = a->head->value;
	pop_head(a);
	push_tail(a, top);
}

void	rb(t_stack *b)
{
	int top;

	top = b->head->value;
	pop_head(b);
	push_tail(b, top);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}