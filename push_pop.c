/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:18:50 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/15 12:30:05 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_head(t_stack *stack, int val)
{
    t_node *new;

    if (!(new = (t_node *)malloc(sizeof(t_node))))
        return ;
    new->value = val;
    stack->head->prev = new;
    new->next = stack->head;
    stack->head = new;
}

void    pop_head(t_stack *stack)
{
    stack->head = stack->head->next;
    stack->head->prev->next = NULL;
    free(stack->head->prev);
    stack->head->prev = NULL;
}

void    push_tail(t_stack *stack, int val)
{
    t_node *new;

    if (!(new = (t_node *)malloc(sizeof(t_node))))
        return ;
    new->value = val;
    stack->tail->next = new;
    new->next = NULL;
    new->prev = stack->tail;
    stack->tail = new;
}

void    pop_tail(t_stack *stack)
{
    stack->tail = stack->tail->prev;
    stack->tail->next->prev = NULL;
    free(stack->tail->next);
    stack->tail->next = NULL;
}
