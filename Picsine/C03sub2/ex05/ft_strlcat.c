/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:47:40 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/01 22:58:08 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int s_len;
	unsigned int d_len;

	s_len = 0;
	d_len = 0;
	while (src[s_len])
		s_len++;
	if (size == 0)
		return (s_len);
	while (dest[d_len])
		d_len++;
	if (size <= d_len)
		return (s_len + size);
	i = 0;
	while (i + d_len + 1 < size && src[i])
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}
