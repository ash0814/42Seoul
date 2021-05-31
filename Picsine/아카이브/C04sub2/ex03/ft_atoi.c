/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:17:14 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/03 21:26:42 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int cnt_m;
	int i;
	int n;

	cnt_m = 0;
	i = 0;
	n = 0;
	while (str[i] <= '/' || str[i] >= ':' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == ' ')
	{
		if (str[i] == '-')
			cnt_m++;
		i++;
	}
	while (str[i] > '/' && str[i] < ':' && str[i] != '\0')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (cnt_m % 2 == 0)
		return (n);
	else
		return (-n);
}
