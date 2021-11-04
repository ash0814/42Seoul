/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:29:30 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/21 11:52:30 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_stack *stack, int value)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		ft_error("malloc ERROR");
	node->value = value;
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->head->prev = NULL;
		stack->tail = node;
		stack->tail->next = NULL;
		stack->size++;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->tail = node;
		stack->tail->next = NULL;
		stack->size++;
	}
}

int		ft_strlen(char *s)
{
	int i;

	i = 1;
	while (s[i])
		i++;
	return (i);
}

void	ft_error(char *s)
{
	int size;

	size = ft_strlen(s);
	write(1, s, size);
	write(1, "\n", 1);
	exit(1);
}

void	check_dup(t_stack *a)
{
	int		*list;
	t_node	*now;
	int		i;
	int		j;

	list = (int *)malloc(sizeof(int) * (a->size));
	now = a->head;
	i = -1;
	while (++i < a->size)
	{
		list[i] = now->value;
		now = now->next;
	}
	i = -1;
	while (++i < a->size - 1)
	{
		j = i;
		while (++j < a->size)
			if (list[i] == list[j])
				ft_error("INPUT NUM DUPLICATE");
	}
	free(list);
}
