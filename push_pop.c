/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:18:50 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/19 16:25:44 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_head(t_stack *stack, int val)
{
    t_node *new;

    if (stack->size == 0)
    {
        addNode(stack, val);
        return ;
    }
    if (!(new = (t_node *)malloc(sizeof(t_node))))
        return ;
    new->value = val;
    stack->head->prev = new;
    new->next = stack->head;
    stack->head = new;
    stack->size++;
}

void    pop_head(t_stack *stack)
{
    if (stack->size == 1)
    {
        free_node(&stack->head);
        stack->head = 0;
        stack->size--;
        return ;
    }
    stack->head = stack->head->next;
    stack->head->prev->next = NULL;
    free(stack->head->prev);
    stack->head->prev = NULL;
    stack->size--;
}

void    push_tail(t_stack *stack, int val)
{
    t_node *new;

    if (stack->size == 0)
    {
        addNode(stack, val);
        return ;
    }
    if (!(new = (t_node *)malloc(sizeof(t_node))))
        return ;
    new->value = val;
    stack->tail->next = new;
    new->next = NULL;
    new->prev = stack->tail;
    stack->tail = new;
    stack->size++;
}

void    pop_tail(t_stack *stack)
{
    if (stack->size == 1)
    {
        free_node(&stack->head);
        stack->head = 0;
        stack->size--;
        return ;
    }
    stack->tail = stack->tail->prev;
    stack->tail->next->prev = NULL;
    free(stack->tail->next);
    stack->tail->next = NULL;
    stack->size--;
}
