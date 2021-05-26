/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:04:01 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/06 16:18:45 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b);

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int count;

	count = 0;
	i = 1;
	while (count < size)
	{
		i = count + 1;
		while (i < size)
		{
			if (tab[count] >= tab[i])
				swap(&tab[count], &tab[i]);
			i++;
		}
		count++;
	}
}

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		main(void)
{
	int arr[]={2, 3, 1, 5, 6};
	ft_sort_int_tab(arr, 5);
	return 0;
}
