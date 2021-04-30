/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:50:22 by sehyan            #+#    #+#             */
/*   Updated: 2021/01/26 13:45:55 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

extern char g_flag;
extern int	g_width;
extern int	g_prec;
extern int	g_check_prec;
extern char	g_format;
extern int	g_return_count;
extern int	g_i;

int		ft_printf(const char *s, ...);
void	ft_info_reset(void);
void	ft_info_reset_all(void);
void	ft_check_format(va_list ap);
void	ft_set_flag_width(const char *s, va_list ap);
void	ft_set_prec_format(const char *s, va_list ap);

void	ft_print_c(va_list ap);
char	*ft_set_cpre(void);
char	*ft_set_csur(void);

void	ft_print_d(va_list ap);
char	*ft_set_dpre(int d, int dlen);
char	*ft_set_check_dpre(int d, char *dpre, int dlen);
char	*ft_set_dstr(int d, int dlen);
char	*ft_set_dsur(int d, int dlen);

void	ft_print_u(va_list ap);
char	*ft_set_upre(unsigned int u, int ulen);
char	*ft_set_check_upre(unsigned int u, char *upre, int ulen);
char	*ft_set_ustr(unsigned int u, int ulen);
char	*ft_set_usur(unsigned int u, int ulen);

void	ft_print_x(va_list ap);
char	*ft_set_xpre(unsigned int u, int xlen);
char	*ft_set_check_xpre(unsigned int u, char *xpre, int xlen);
char	*ft_set_xstr(unsigned int u, int xlen);
char	*ft_set_xsur(unsigned int u, int xlen);

void	ft_print_p(va_list ap);
char	*ft_set_ppre(unsigned long long u, int plen);
char	*ft_set_check_ppre(unsigned long long u, char *ppre, int plen);
char	*ft_set_pstr(unsigned long long u, int plen);
char	*ft_set_psur(unsigned long long u, int plen);

void	ft_print_s(va_list ap);
char	*ft_set_spre(int slen);
char	*ft_set_sstr(char *s);
char	*ft_set_ssur(int slen);

char	*ft_hexa(unsigned int n);
char	*ft_hexa_ptr(unsigned long long n);
void	ft_rev(char *s, int len);

void	ft_write_str(char *s);
void	ft_write_char(char c);
int		ft_put_char(char *s, char c, int len);
char	*ft_calloc_put(char *s, char c, int len);
void	ft_put_minus(char *s);
#endif
