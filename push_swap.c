/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:42:51 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/15 17:27:38 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *node)
{
	t_node *now;

	now = node;
	while (now)
	{
		printf(" > %d", now->value);
		now = now->next;
	}
	printf("\n");
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
	check_dup(stack_a);
	print_stack(stack_a->head);

	free_stack(stack_a, stack_b);
	return (0);
}