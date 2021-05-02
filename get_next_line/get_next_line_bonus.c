/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:08:07 by sehyan            #+#    #+#             */
/*   Updated: 2021/03/29 12:29:30 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_index(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (i);
	return (-1);
}

int	ft_fill(char **bkup, char **line, int i)
{
	int		k;
	char	*tmp;

	if (!(*line = (char *)malloc(i + 1)))
		return (-1);
	k = -1;
	while (++k < i)
		(*line)[k] = (*bkup)[k];
	(*line)[k] = 0;
	if (ft_strlen(&(*bkup)[i + 1]) == 0)
	{
		free(*bkup);
		*bkup = 0;
	}
	else
	{
		tmp = ft_strdup(&(*bkup)[i + 1]);
		free(*bkup);
		*bkup = ft_strdup(tmp);
		free(tmp);
	}
	return (1);
}

int	ft_last_fill(char **bkup, char **line)
{
	if (!(*bkup))
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ft_index(*bkup) >= 0)
		return (ft_fill(bkup, line, ft_index(*bkup)));
	*line = *bkup;
	*bkup = 0;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *bkup[OPEN_MAX];
	char		*buf;
	int			rd_size;

	if (!bkup[fd])
		bkup[fd] = ft_strdup("");
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)) || line == 0 || fd < 0
			|| BUFFER_SIZE <= 0)
		return (-1);
	while ((rd_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = 0;
		bkup[fd] = ft_strjoin(bkup[fd], buf);
		free(buf);
		if (ft_index(bkup[fd]) >= 0)
			return (ft_fill(&bkup[fd], line, ft_index(bkup[fd])));
		if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
			return (-1);
	}
	free(buf);
	if (rd_size < 0)
		return (-1);
	return (ft_last_fill(&bkup[fd], line));
}
