/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:42:51 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/12 16:26:13 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addNode(t_list *A, int value)
{
	t_node	*node = (t_node *)malloc(sizeof(t_node));

	node->value = value;
	if (A->head == NULL)
	{

		A->head = node;
		A->tail = node;
	}
	else
	{

		A->tail->next = node;
		node->prev = A->tail;
		A->tail = node;
	}
}

void	rmTailNode(t_list *A)
{
	if (!A)
		return ;
	A->tail = A->tail->prev;
}

int		main(int argc, char *argv[])
{
	t_list *stack_a;
	t_list *stack_b;
	int		i;

	stack_a = (t_list *)malloc(sizeof(t_list));
	stack_b = (t_list *)malloc(sizeof(t_list));
	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	i = 0;
	while (++i < argc)
		makeNode(stack_a, ft_atoi(argv[i]));
	return (0);
}