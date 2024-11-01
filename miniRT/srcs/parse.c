/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:43:39 by sehyan            #+#    #+#             */
/*   Updated: 2021/05/27 10:28:35 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parse(char *argv, t_scene *scene)
{
	int		fd;
	char	buf[5000000];
	int		i;
	char	**line;
	int		flag;

	i = 0;
	flag = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_error("FILE OPEN FAIL\n");
	if (read(fd, &buf, 5000000) < 0)
		ft_error("FILE READ ERROR_buf\n");
	if (!(line = ft_split(buf, '\n')))
		ft_error("PASING ERROR_line\n");
	while (i < len_spl(line))
	{
		check_file(line[i], scene, flag);
		i++;
	}
	double_free(line);
	close(fd);
}

void	check_len_one(char **words, t_scene *scene, int flag)
{
	if (words[0][0] == 'R')
		parse_r(words, scene);
	else if (words[0][0] == 'A')
		parse_a(words, scene);
	else if (words[0][0] == 'c')
	{
		flag++;
		parse_c(words, scene, flag);
	}
	else if (words[0][0] == 'l')
		parse_l(words, scene);
	else if (words[0][0] == '#')
		;
}

void	check_file(char *str, t_scene *scene, int flag)
{
	char	**words;

	if (!(words = ft_split_wsp(str)))
		ft_error("PARSING ERROR_split\n");
	if (ft_strlen(words[0]) == 1)
	{
		check_len_one(words, scene, flag);
	}
	else if (ft_strlen(words[0]) == 2)
	{
		if (words[0][0] == 'c' && words[0][1] == 'y')
			parse_cy(words, scene);
		else if (words[0][0] == 'p' && words[0][1] == 'l')
			parse_pl(words, scene);
		else if (words[0][0] == 't' && words[0][1] == 'r')
			parse_tr(words, scene);
		else if (words[0][0] == 's' && words[0][1] == 'p')
			parse_sp(words, scene);
		else if (words[0][0] == 's' && words[0][1] == 'q')
			parse_sq(words, scene);
	}
	else
		ft_error("PASING ERROR_words\n");
	double_free(words);
}
