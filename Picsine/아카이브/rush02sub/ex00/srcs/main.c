/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 10:21:29 by sehyan            #+#    #+#             */
/*   Updated: 2020/12/07 11:10:37 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*g_dictname = "numbers.dict";
char	g_buf[1024];
int		g_wasspace = 0;
int		g_isfirst = 1;
int		g_error = 0;

int		dict_trim(int fd)
{
	char	tc;
	int		has_delim;

	tc = 0;
	ft_make_zero(&has_delim, &g_wasspace);
	g_isfirst = (g_isfirst == 0) ? write(1, " ", 1) == 0 : 0;
	read(fd, &tc, 1);
	while (tc == ' ' || (tc == ':' && !has_delim))
	{
		has_delim = (tc == ':') ? 1 : has_delim;
		if (!read(fd, &tc, 1))
			break ;
	}
	while (tc == ' ' && read(fd, &tc, 1))
		;
	while (tc != '\n' && tc != 0)
	{
		if (tc == ' ' && g_wasspace == 0)
			g_wasspace = 1;
		else if (tc != ' ')
			ft_putchar(tc);
		if (!read(fd, &tc, 1))
			break ;
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

void	dict_print(char *key)
{
	int	total;
	int len;

	if (ft_strlen(key, &total) > 37 + 2)
		return (print_dict_err());
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
		else if (key[total - len--] == '0' && len + 1 == 1 && g_isfirst)
			dict_printval('0');
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_is_valid(argv[1]))
			write(1, "Error", 5);
		else
			dict_print(argv[1]);
	}
	else if (argc == 3)
	{
		if (!ft_is_valid(argv[2]))
			write(1, "Error", 5);
		else
		{
			g_dictname = argv[1];
			dict_print(argv[2]);
		}
	}
	else
		write(1, "Error", 5);
	if (g_error)
		print_dict_err();
	write(1, "\n", 1);
}
