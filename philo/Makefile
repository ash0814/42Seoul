# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 14:40:31 by sehyan            #+#    #+#              #
#    Updated: 2021/11/17 16:51:13 by sehyan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	gcc #-Wall -Wextra -Werror
CF		=	-lpthread -I ./
SRC		=	main.c philo.c init.c

SRC_DIR = ./srcs/

SRCS = $(addprefix $(SRC_DIR),$(SRC))

OBJ = $(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	$(SRC_DIR)/%.c
			$(CC) $(CF) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CF) $(SRCS) -o $(NAME)
	make clean

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)


re		:	fclean	all

.PHONY	:	all clean fclean re