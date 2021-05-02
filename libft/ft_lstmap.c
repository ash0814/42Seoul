/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:18:00 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/27 02:52:07 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list *tmp;
	t_list *head;
	t_list *result;

	if (lst == 0)
		return (0);
	head = ft_lstnew((*f)(lst->content));
	if (head == 0)
		return (0);
	result = head;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (tmp == 0)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		result->next = tmp;
		result = tmp;
		lst = lst->next;
	}
	return (head);
}
