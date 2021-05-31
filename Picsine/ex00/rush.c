/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 10:21:29 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/05 20:28:37 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*g_dictname = "numbers.dict";
char	g_buf[1024];
int		g_wasspace = 0;
int		g_isfirst = 1;
int		g_error = 0;

int		ft_is_valid(char *str)
{
	int		i;

	if (!*str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	print_dict_err(void)
{
	write(1, "Dict Error\n", 11);
}

void	ft_puttc(char tc, int ws)
{
	g_wasspace = ws;
	write(1, &tc, 1);
}

void	ft_clear_buf(void)
{
	int i;

	i = 0;
	while (i < 1024)
		g_buf[i++] = 0;
}

int		dict_trim(int fd)
{
	char	tc;
	int		has_delim=0;

	tc = 0;
	g_isfirst = (g_isfirst == 0) ? write(1, " ", 1) == 0 : 0;
	g_wasspace = 0;
	read(fd, &tc, 1);
	while (tc == ' ' || (tc == ':' && !has_delim))
	{
		if (tc == ':')
			has_delim = 1;
		if (!read(fd, &tc, 1))
			break ;
	}
	while (tc == ' ')
		if (!read(fd, &tc, 1))
			break ;
	while (tc != '\n' && tc != 0)
	{
		if (tc == ' ')
		{
			g_wasspace == 0 ? ft_puttc(tc, 1) : 1;
			if (!read(fd, &tc, 1))
				break ;
		}
		else
		{
			ft_puttc(tc, 0);
			if (!read(fd, &tc, 1))
				break ;
		}
	}
	return (1);
}

void	ft_nextline(int fd)
{
	char	tc;

	tc = 0;
	while (tc != '\n')
		if (!read(fd, &tc, 1))
		{
			g_error = 1;
			return ;
		}
}

int		ft_strlen(char *str, int *total)
{
	int flag;
	int len;
	int	i;

	i = 0;
	flag = 1;
	len = 0;
	while (str[i])
	{
		if (flag == 1 && str[i] != '0')
			flag = 0;
		else if (flag == 1 && str[i] == '0')
			i++;
		else
		{
			i++;
			len++;
		}
	}
	*total = i; 
	return (len);
}

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
	close(fd);
	return (0);
}

int		dict_printval2(char c1, char c2)
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
		if (g_buf[0] == c1 && g_buf[1] == '0' &&
				(g_buf[2] == ' ' || g_buf[2] == ':'))
		{
			if (g_buf[0] == '1' && g_buf[1] != c2)
				continue;
			dict_trim(fd);
			if (c1 != '1' && c2 != '0')
				dict_printval(c2);
			break ;
		}
		else
			ft_nextline(fd);
	}
	close(fd);
	return (0);
}

int		dict_printval3(char c1, char c2, char c3)
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
	close(fd);
	return (0);
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
	close(fd);
	return (0);
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

void	dict_print(char *key)
{
	int	total;
	int len;

	if (ft_strlen(key, &total) > 37 + 2)
	{
		print_dict_err();
		return ;
	}
	len = total;
	while (len > 0)
	{
		if (key[total - len] != '0')
		{
			if (len == 1)
				dict_printval(key[total - len]);
			else if (len == 2)
				dict_printval2(key[total - len], key[total - len + 1]);
			else if (len == 3)
				dict_printval3(key[total - len],
						key[total - len + 1], key[total - len + 2]);
			else
				dict_printvaln(total, len, key);
			len = (len % 3 == 0) ? len - 3 : len - (len % 3);
		}
		else
			len--;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_is_valid(argv[1]))
			write(1, "Error\n", 6);
		else
			dict_print(argv[1]);
	}
	else if (argc == 3)
	{
		if (!ft_is_valid(argv[2]))
			write(1, "Error\n", 6);
		else
		{
			g_dictname = argv[1];
			dict_print(argv[2]);
		}
	}
	else
		write(1, "Error\n", 6);
	if (g_error)
		print_dict_err();
}
