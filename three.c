/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:41:08 by ash               #+#    #+#             */
/*   Updated: 2021/06/20 17:51:52 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    three_sort(t_stack *a)
{
    int x;
	int y;
	int z;
    
    x = a->head->value;
    y = a->head->next->value;
    z = a->head->next->next->value;
	if (x > y && y < z && z > x)
		sa(a);
	else if (x < y && y > z && x > z)
		rra(a);
	else if (x > y && x > z && y < z)
        ra(a);
    else if (y > z)
	{
	    if (x > y && x > z)
		    ra(a);
        else if (x < y && z > x)
		    rra(a);
		sa(a);
	}
	return ;
}