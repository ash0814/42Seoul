/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:42:51 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/16 22:13:25 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *node)
{
	t_node *now;

	now = node;
	while (now)
	{
		printf(" %d", now->value);
		now = now->next;
	}
	printf("\n");
}

int		main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	int		i;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a->head = NULL;
	a->tail = NULL;
	b->head = NULL;
	b->tail = NULL;
	i = 0;
	while (++i < argc)
		addNode(a, ft_atoi(argv[i]));
	check_dup(a);
	print_stack(a->head);

	a_to_b(a->size, a, b);
	// print_stack(a->head);
	free_stack(a, b);
	return (0);
}