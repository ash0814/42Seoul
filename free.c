/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:05:54 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/21 12:06:05 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_node **node)
{
	t_node **now;
	t_node *tmp;

	now = node;
	while (*now)
	{
		tmp = *now;
		*now = (*now)->next;
		free(tmp);
		tmp = 0;
	}
}

void	free_stack(t_stack *a)
{
	free_node(&a->head);
	free(a);
	a = 0;
}
