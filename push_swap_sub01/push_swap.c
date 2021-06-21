/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:42:51 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/21 11:52:06 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sort(t_stack *stack)
{
	int		list[stack->size];
	int		i;
	int		j;
	t_node	*now;

	i = 0;
	now = stack->head;
	while (now)
	{
		list[i] = now->value;
		now = now->next;
		i++;
	}
	q_sort(0, i - 1, list);
	j = -1;
	now = stack->head;
	while (now && ++j < i)
	{
		if (list[j] != now->value)
			return (0);
		else
			now = now->next;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	int		i;

	if (!(a = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	if (!(b = (t_stack *)malloc(sizeof(t_stack))))
	{
		free_stack(a);
		return (0);
	}
	a->head = NULL;
	a->tail = NULL;
	b->head = NULL;
	b->tail = NULL;
	i = 0;
	while (++i < argc)
		add_node(a, ft_atoi(argv[i]));
	check_dup(a);
	if (check_sort(a) == 1)
		return (0);
	a_to_b(a->size, a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
