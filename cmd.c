/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:18:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/19 19:24:40 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern int res;

void    sa(t_stack *a)
{
    int one;
	int two;
	
	if (a->size < 2)
		return ;
	one = a->head->value;
	two = a->head->next->value;
	pop_head(a);
	pop_head(a);
	push_head(a, one);
	push_head(a, two);
	res++;
	write(1, "sa\n", 3);
}

void    sb(t_stack *b)
{
    int one;
	int two;

	if (b->size < 2)
		return ;
	one = b->head->value;
	two = b->head->next->value;
	pop_head(b);
	pop_head(b);
	push_head(b, one);
	push_head(b, two);
	res++;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
    sa(a);
	sb(b);
	res--;
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	int b_top;

	if (b->size < 1)
		return ;
	b_top = b->head->value;
	pop_head(b);
	push_head(a, b_top);
	res++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int a_top;
	
	if (a->size < 1)
		return ;
	a_top = a->head->value;
	pop_head(a);
	push_head(b, a_top);
	res++;
	write(1, "pb\n", 3);
}
