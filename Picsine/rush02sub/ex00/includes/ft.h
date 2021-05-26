/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:24:27 by jongpark          #+#    #+#             */
/*   Updated: 2020/12/06 13:28:45 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_is_valid(char *str);
void	print_dict_err(void);
void	ft_puttc(char tc, int ws);
int		ft_clear_buf(void);
void	ft_make_zero(int *i1, int *i2);
int		dict_trim(int fd);
void	ft_nextline(int fd);
int		ft_strlen(char *str, int *total);
int		dict_printval(char c);
int		dict_printval2(char c1, char c2);
int		dict_printval3(char c1, char c2, char c3);
int		dict_printpos(int len);
void	dict_printvaln(int total, int len, char *key);
void	dict_print(char *key);
void	ft_putchar(char tc);

#endif
