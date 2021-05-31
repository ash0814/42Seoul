/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 00:25:22 by seungoh           #+#    #+#             */
/*   Updated: 2020/12/01 16:37:08 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *first;
	char *find_str;

	if (*to_find == 0)
		return (char *)str;
	while (*str)
	{
		if (*str == *to_find)
		{
			first = str + 1;
			find_str = to_find + 1;
			while (*find_str != 0 && *first != 0 && *first == *find_str)
			{
				first++;
				find_str++;
			}
			if (*find_str == 0)
				return (char *)str;
			if (*first == 0)
				break ;
		}
		str++;
	}
	return (0);
}
