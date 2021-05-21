# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 19:54:45 by sehyan            #+#    #+#              #
#    Updated: 2021/05/21 15:46:28 by sehyan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minirt

#
# SRCS and OBJS
#
SRCS	=	./srcs/camera.c ./srcs/canvas.c ./srcs/ft_atoif.c ./srcs/hit_obj.c ./srcs/hit_obj2.c \
			./srcs/hit.c ./srcs/hook.c ./srcs/init.c ./srcs/main.c ./srcs/object_create.c ./srcs/objects.c \
			./srcs/parse_object.c ./srcs/parse_object2.c ./srcs/parse.c ./srcs/phong.c ./srcs/ray.c \
			./srcs/split_utils.c ./srcs/split_utils2.c ./srcs/utils.c ./srcs/utils2.c ./srcs/vec_utils.c \
			./srcs/vec_utils2.c ./srcs/vec_utils3.c

OBJ = $(SRCS:.c=.o)
#
# Compiler and flags
#

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra #-fsanitize=address -g
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

#
# Rules
#

# test	: re
# 			./minirt 1.rt

all		: $(NAME)

bonus	: all

%.o	:%.c
	$(CC) -Imlx $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CLIB) $(OBJ) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all

.PHONY: all clean fclean re