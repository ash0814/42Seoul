/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:40:37 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/17 17:35:34 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int top;

	if (a->size < 2)
		return ;
	top = a->head->value;
	pop_head(a);
	push_tail(a, top);
}

void	rb(t_stack *b)
{
	int top;

	if (b->size < 2)
		return ;
	top = b->head->value;
	pop_head(b);
	push_tail(b, top);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}