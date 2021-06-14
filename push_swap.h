/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:08:32 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/12 16:23:10 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node t_node;

typedef struct s_node
{
	int		value;
	t_node *prev;
	t_node *next;
}				t_node;

typedef struct s_stack
{
	t_node *head;
	t_node *tail;
}				t_stack;

int			ft_atoi(const char *str);
void	addNode(t_stack *A, int value);
void    push_head(t_stack *stack, int val);
void    pop_head(t_stack *stack);
void    push_tail(t_stack *stack, int val);
void	pop_tail(t_stack *stack);
#endif