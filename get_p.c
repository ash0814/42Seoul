/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:49:34 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/19 17:01:17 by sehyan           ###   ########.fr       */
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

	// if (left >= right)
	// 	return ;
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
	// for (int k = 0; k < r; k++)
	// 	printf("list[%d] = %d\n", k, list[k]);
	p = list[r / 2];
	return (p);
}

void	a_to_b(int r, t_stack *a, t_stack *b)
{
	int p = get_p(a, r);
	int i = 0;
	int	ra_t = 0;
	int pb_t = 0;

	printf("r = %d\n", r);
	if (r == 1){
		print_stack(a->head);
		print_stack(b->head);
		printf("^^^^^^^atob^^^^^^\n");
		printf("-----------------fin.----------------\n");
		return ;
	}
	printf("p = %d\n", p);
	while (i < r && a->head)
	{
		if (a->head->value >= p){
			ra(a);
			ra_t++;
		}
		else
		{
			pb(a, b);
			pb_t++;
		}
		i++;
	}
	i = -1;
	while (++i < ra_t)
		rra(a);
	print_stack(a->head);
	print_stack(b->head);
	printf("^^^^^^^atob^^^^^^\n");
	a_to_b(ra_t, a, b);
	b_to_a(pb_t, a, b);
}

void	b_to_a(int r, t_stack *a, t_stack *b)
{
	int p = get_p(b, r);
	int i = 0;
	int	rb_t = 0;
	int pa_t = 0;

	printf("r = %d\n", r);
	if (r == 1)
	{
		pa(a, b);
		print_stack(a->head);
		print_stack(b->head);
		printf("^^^^^^^^^btoa^^^^^^^^^^^\n");
		printf("-----------------fin.----------------\n");
		return ;
	}
	printf("p = %d\n", p);
	while (i < r && a->head)
	{
		if (b->head->value >= p){
			pa(a, b);
			pa_t++;
		}
		else
		{
			rb(b);
			rb_t++;
		}
		i++;
	}
	i = -1;
	while (++i < rb_t)
		rrb(b);
	print_stack(a->head);
	print_stack(b->head);
	printf("^^^^^^^^^btoa^^^^^^^^^^^\n");
	a_to_b(pa_t, a, b);
	b_to_a(rb_t, a, b);
}
