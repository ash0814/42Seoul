/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:59:03 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/03 09:52:12 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *p1;
	char *p2;

	if (*to_find == 0)
		return (str);
	while (*str != 0)
	{
		if (*str == *to_find)
		{
			p1 = str + 1;
			p2 = to_find + 1;
			while (*p1 == *p2 && *p1 != 0 && *p2 != 0)
			{
				p1++;
				p2++;
			}
			if (*p2 == 0)
				return (str);
			if (*p1 == 0)
				break ;
		}
		str++;
	}
	return (0);
}
