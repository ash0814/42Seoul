# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 12:22:42 by sehyan            #+#    #+#              #
#    Updated: 2021/01/26 14:34:44 by sehyan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all re clean fclean libft
CC = gcc
CF = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_util.c ft_printf_util2.c ft_print_c.c\
	   ft_print_d.c ft_print_u.c ft_print_x.c ft_print_p.c ft_print_s.c
OBJS = $(SRCS:.c=.o)
LIBFT = -L./libft -lft

all : $(NAME)

.c.o:
	$(CC) $(CF) -c $<

$(NAME):$(OBJS)
	$(MAKE) -C ./libft all
	cp libft/libft.a ./$(NAME)
	ar rsc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	$(MAKE) -C ./libft clean
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) -C ./libft fclean
	rm -rf $(NAME)

re : fclean all clean
