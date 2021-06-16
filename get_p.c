/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:49:34 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/16 16:08:26 by sehyan           ###   ########.fr       */
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
	j = p;
	i = left + 1;
	if (left < right)
	{
		while (i <= right)
		{
			if (list[i] < list[p])
			{
				j++;
				swap(&list[j], &list[i]);
			}
			swap(&list[left], &list[j]);
			p = j;
			q_sort(left, p - 1, list);
			q_sort(p + 1, right, list);
			i++;
		}
	}
}

void	get_p(t_stack *stack)
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
	printf("p = %d\n", p);
}