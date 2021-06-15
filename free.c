/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:26:47 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/15 17:27:18 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_node **node)
{
	t_node **now;
	t_node *tmp;

	now = node;
	// printf("here\n");
	while (*now)
	{
		tmp = *now;
		*now = (*now)->next;
		free(tmp);
		tmp = 0;
	}
}

void	free_stack(t_stack *a, t_stack *b)
{
	free_node(&a->head);
	free(a);
	a = 0;
	free(b);
	b = 0;
}