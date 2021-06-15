/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:18:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/15 12:39:54 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack *a)
{
    int one;
	int two;

	one = a->head->value;
	two = a->head->next->value;
	pop_head(a);
	pop_head(a);
	push_head(a, one);
	push_head(a, two);
}

void    sb(t_stack *b)
{
    int one;
	int two;

	one = b->head->value;
	two = b->head->next->value;
	pop_head(b);
	pop_head(b);
	push_head(b, one);
	push_head(b, two);
}

void	ss(t_stack *a, t_stack *b)
{
    sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	int b_top;

	b_top = b->head->value;
	pop_head(b);
	push_head(a, b_top);
}

void	pb(t_stack *a, t_stack *b)
{
	int a_top;

	a_top = a->head->value;
	pop_head(a);
	push_head(b, a_top);
}