/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:49:34 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/16 22:12:24 by sehyan           ###   ########.fr       */
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
			{
				swap(&list[j], &list[p]);
			}
			else
				swap(&list[i], &list[j]);
		}
		q_sort(left, j - 1, list);
		q_sort(j + 1, right, list);
	}
}



int		get_p(t_stack *stack)
{
	int p;
	int *list;
	int i;
	t_node *now;

	i = 0;
	list = (int *)malloc(sizeof(int) * stack->size);
	now = stack->head;
	while (now)
	{
		list[i] = now->value;
		now = now->next;
		i++;
	}
	q_sort(0, stack->size - 1, list);
	p = list[stack->size / 2];
	return (p);
}

void	a_to_b(int r, t_stack *a, t_stack *b)
{
	int p = get_p(a);
	int i = 0;
	int	ra_t = 0;
	int pb_t = 0;

	printf("\np = %d\n", p);
	if (r < 3)
		return ;
	while (i < r && a->head)
	{
		// printf(" <%d, %d> \n", i, (*now)->value);
		if (a->head->value > p){
			pb(a, b);
			pb_t++;
		}
		else
		{
			ra(a);
			ra_t++;
		}
		i++;
	}
	printf("===stack_a\n");
	print_stack(a->head);
	printf("===stack_b\n");
	print_stack(b->head);
	a_to_b(ra_t, a, b);
}