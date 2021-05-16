# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 19:54:45 by sehyan            #+#    #+#              #
#    Updated: 2021/05/16 20:35:29 by sehyan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minirt

#
# SRCS and OBJS
#
SRCS_LIB = ./srcs/
SRCS	=	main.c

OBJ = $(SRC:.c=.o)
#
# Compiler and flags
#

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

#
# Rules
#

test	: re
			./minirt 1.rt

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CLIB) $(addprefix $(SRCS_LIB), $(SRCS)) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all