/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:42:51 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/15 13:02:12 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addNode(t_stack *A, int value)
{
	t_node	*node = (t_node *)malloc(sizeof(t_node));

	node->value = value;
	if (A->head == NULL)
	{
		A->head = node;
		A->head->prev = NULL;
		A->tail = node;
		A->tail->next = NULL;
	}
	else
	{
		A->tail->next = node;
		node->prev = A->tail;
		A->tail = node;
		A->tail->next = NULL;
	}
}

void	ft_error(char *s)
{
	printf("%s\n", s);
	exit(1);
}

int		main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		i;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	i = 0;
	while (++i < argc)
		addNode(stack_a, ft_atoi(argv[i]));
	printf("%d -> %d -> %d -> %d\n", stack_a->head->value,
									stack_a->head->next->value,
									stack_a->head->next->next->value,
									stack_a->head->next->next->next->value);
	push_head(stack_a, 5);
	printf("%d -> %d -> %d -> %d\n", stack_a->head->value,
									stack_a->head->next->value,
									stack_a->head->next->next->value,
									stack_a->head->next->next->next->value);
	pop_head(stack_a);
	pop_head(stack_a);
	push_tail(stack_a, 10);
	printf("%d -> %d -> %d -> %d -> %d\n", stack_a->head->value,
									stack_a->head->next->value,
									stack_a->head->next->next->value,
									stack_a->head->next->next->next->value,
									stack_a->tail->value);
	pop_tail(stack_a);
	printf("%d -> %d -> %d -> %d -> %d\n", stack_a->head->value,
									stack_a->head->next->value,
									stack_a->head->next->next->value,
									stack_a->head->next->next->next->value,
									stack_a->tail->value);
	sa(stack_a);
	printf("%d -> %d -> %d -> %d -> %d\n", stack_a->head->value,
									stack_a->head->next->value,
									stack_a->head->next->next->value,
									stack_a->head->next->next->next->value,
									stack_a->tail->value);
	return (0);
}
