/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:32:00 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/06 13:27:56 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern char		*g_dictname;
extern char		g_buf[1024];
extern int		g_wasspace;
extern int		g_isfirst;
extern int		g_error;

int		dict_printval(char c)
{
	int		fd;
	int		i;

	if ((fd = open(g_dictname, O_RDONLY)) == -1)
		return (g_error = 1);
	while (g_error != 1)
	{
		ft_clear_buf();
		i = -1;
		while (read(fd, &g_buf[++i], 1))
		{
			if (g_buf[i] == '\n')
				i--;
			if (g_buf[i] == ' ' | g_buf[i] == ':')
				break ;
		}
		if (g_buf[0] == c && (g_buf[1] == ' ' || g_buf[1] == ':'))
		{
			dict_trim(fd);
			break ;
		}
		else
			ft_nextline(fd);
	}
	return (close(fd));
}

int		dict_printval2(char c1, char c2)
{
	int		fd;
	int		i;

	if ((fd = open(g_dictname, O_RDONLY)) == -1)
		return (g_error = 1);
	while (g_error != 1 && ft_clear_buf())
	{
		i = -1;
		while (read(fd, &g_buf[++i], 1))
			if (g_buf[i] == ' ' || g_buf[i] == ':')
				break ;
		if (g_buf[0] == c1 && (g_buf[2] == ' ' || g_buf[2] == ':'))
		{
			if ((c1 != '1' && g_buf[1] != '0') ||
				(g_buf[0] == '1' && g_buf[1] != c2))
				continue;
			dict_trim(fd);
			if (c1 != '1' && c2 != '0')
				dict_printval(c2);
			break ;
		}
		else
			ft_nextline(fd);
	}
	return (close(fd));
}

int		dict_printval3(char c1, char c2, char c3)
{
	int		fd;
	int		i;

	if ((fd = open(g_dictname, O_RDONLY)) == -1)
		return (g_error = 1);
	while (g_error != 1 && ft_clear_buf())
	{
		i = -1;
		while (read(fd, &g_buf[++i], 1))
			if (g_buf[i] == ' ' || g_buf[i] == ':')
				break ;
		if (g_buf[0] == '1' && g_buf[1] == '0' && g_buf[2] == '0'
				&& (g_buf[3] == ' ' || g_buf[3] == ':'))
		{
			dict_printval(c1);
			if (dict_trim(fd) && c2 != '0')
				dict_printval2(c2, c3);
			else if (c2 == '0' && c3 != '0')
				dict_printval(c3);
			break ;
		}
		else
			ft_nextline(fd);
	}
	return (close(fd));
}

int		dict_printpos(int len)
{
	int		fd;
	int		i;

	if ((fd = open(g_dictname, O_RDONLY)) == -1)
		return (g_error = 1);
	while (g_error != 1)
	{
		ft_clear_buf();
		i = -1;
		while (read(fd, &g_buf[++i], 1))
			if (g_buf[i] == ' ' || g_buf[i] == ':')
				break ;
		if (g_buf[0] == '1')
		{
			i = 1;
			while (g_buf[i] == '0')
				i++;
			if (i == len && dict_trim(fd))
				break ;
		}
		else
			ft_nextline(fd);
	}
	return (close(fd));
}

void	dict_printvaln(int total, int len, char *key)
{
	if (len % 3 == 0)
		dict_printval3(key[total - len],
				key[total - len + 1], key[total - len + 2]);
	else if (len % 3 == 1)
		dict_printval(key[total - len]);
	else if (len % 3 == 2)
		dict_printval2(key[total - len], key[total - len + 1]);
	if (len % 3 == 0)
		dict_printpos(len - 2);
	else
		dict_printpos((len / 3) * 3 + 1);
}
