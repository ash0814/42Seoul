# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 19:54:45 by sehyan            #+#    #+#              #
#    Updated: 2021/05/27 14:00:12 by sehyan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

SRCS	=	./srcs/camera.c ./srcs/canvas.c ./srcs/ft_atoif.c \
			./srcs/hit_obj.c ./srcs/hit_obj2.c ./srcs/hit.c ./srcs/hook.c \
			./srcs/init.c ./srcs/main.c ./srcs/object_create.c ./srcs/objects.c \
			./srcs/parse_object.c ./srcs/parse_object2.c ./srcs/parse.c\
			./srcs/phong.c ./srcs/ray.c ./srcs/split_utils.c\
			./srcs/split_utils2.c ./srcs/utils.c ./srcs/utils2.c\
			./srcs/vec_utils.c ./srcs/vec_utils2.c ./srcs/vec_utils3.c\
			./srcs/utils3.c ./srcs/save.c ./srcs/image.c

OBJ = $(SRCS:.c=.o)

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

all		: $(NAME)

bonus	: all

%.o	:%.c
	$(CC) -Imlx $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) $(CLIB) $(OBJ) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJ)
	$(MAKE) -C ./mlx clean

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all

.PHONY: all clean fclean re
