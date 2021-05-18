# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 19:54:45 by sehyan            #+#    #+#              #
#    Updated: 2021/05/18 16:23:42 by sehyan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minirt

#
# SRCS and OBJS
#
SRCS_LIB = ./srcs/
SRCS	=	camera.c canvas.c ft_atoif.c hit_obj.c hit_obj2.c \
			hit.c hook.c init.c main.c object_create.c objects.c \
			parse_object.c parse_object2.c parse.c phong.c ray.c \
			split_utils.c split_utils2.c utils.c utils2.c vec_utils.c \
			vec_utils2.c vec_utils3.c

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

# test	: re
# 			./minirt 1.rt

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