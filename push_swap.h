/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:06:22 by sehyan            #+#    #+#             */
/*   Updated: 2021/06/21 12:14:57 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	int				size;
	t_node			*head;
	t_node			*tail;
}				t_stack;

int				ft_atoi(const char *str);
void			ft_error(char *s);
void			add_node(t_stack *stack, int value);
void			check_dup(t_stack *a);
void			push_head(t_stack *stack, int val);
void			pop_head(t_stack *stack);
void			push_tail(t_stack *stack, int val);
void			pop_tail(t_stack *stack);
void			free_node(t_node **node);
void			free_stack(t_stack *a);
int				sa(t_stack *a);
int				sb(t_stack *b);
int				ss(t_stack *a, t_stack *b);
int				pa(t_stack *a, t_stack *b);
int				pb(t_stack *a, t_stack *b);
int				ra(t_stack *a);
int				rb(t_stack *b);
int				rr(t_stack *a, t_stack *b);
int				rra(t_stack *a);
int				rrb(t_stack *b);
int				rrr(t_stack *a, t_stack *b);
int				get_p(t_stack *stack, int r);
void			q_sort(int left, int right, int *list);
void			a_to_b(int r, t_stack *a, t_stack *b);
void			b_to_a(int r, t_stack *a, t_stack *b);
int				check_sort(t_stack *stack);
void			three_sort(t_stack *a);
void			check_three_val_b(t_stack *a, t_stack *b, int r);
void			check_three_val(t_stack *a, int r);
#endif
