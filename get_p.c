/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:49:34 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/20 19:08:23 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void	q_sort(int left, int right, int *list)
{
	int p;
	int j;
	int i;

	p = left;
	i = left + 1;
	j = right;
	if (left < right)
	{
		while (i <= j)
		{
			while (i <= right && list[i] <= list[p])
				i++;
			while (j > left && list[j] >= list[p])
				j--;
			if (i > j)
				swap(&list[j], &list[p]);
			else
				swap(&list[i], &list[j]);
		}
		q_sort(left, j - 1, list);
		q_sort(j + 1, right, list);
	}
}

int		get_p(t_stack *stack, int r)
{
	int p;
	int *list;
	int i;
	t_node *now;
 
	i = 0;
	list = (int *)malloc(sizeof(int) * r);
	now = stack->head;
	while (now && i < r)
	{
		list[i] = now->value;
		now = now->next;
		i++;
	}
	q_sort(0, r - 1, list);
	p = list[r / 2];
	free(list);
	return (p);
}

void	a_to_b(int r, t_stack *a, t_stack *b)
{
	int p;
	int i;
	int	ra_t;
	int pb_t;

	i = -1;
	ra_t = 0;
	pb_t = 0;
	if (r < 3 || a->size == 3)
	{
		if (a->size == 3)
			three_sort(a);
		else if (r == 2 && a->head->value > a->head->next->value)
			sa(a);
		return ;
	}
	p = get_p(a, r);
	while (++i < r && a->head)
	{
		if (a->head->value >= p)
			ra_t += ra(a);
		else
			pb_t += pb(a, b);
	}
	i = -1;
	while (++i < ra_t && ra_t != a->size)
		rra(a);
	a_to_b(ra_t, a, b);
	b_to_a(pb_t, a, b);
}

void	b_to_a(int r, t_stack *a, t_stack *b)
{
	int p;
	int i;
	int	rb_t;
	int pa_t;

	p = get_p(b, r);
	i = -1;
	rb_t = 0;
	pa_t = 0;
	if (r < 3)
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
	while (++i < r && a->head)
	{
		if (b->head->value >= p)
			pa_t += pa(a, b);
		else
			rb_t += rb(b);
	}
	i = -1;
	while (++i < rb_t && b->size != rb_t)
		rrb(b);
	a_to_b(pa_t, a, b);
	b_to_a(rb_t, a, b);
}
