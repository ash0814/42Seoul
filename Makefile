# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ash <ash@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 12:30:11 by sehyan            #+#    #+#              #
#    Updated: 2021/06/20 17:48:59 by ash              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc
CF		=	-Wall -Wextra -Werror -I ./
SRC	=	push_swap.c ft_atoi.c push_pop.c cmd.c cmd_r.c cmd_rr.c \
		utils.c free.c get_p.c three.c\

SRC_DIR = ./

SRCS = $(addprefix $(SRC_DIR),$(SRC))

OBJ = $(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	$(SRC_DIR)/%.c
			$(CC) $(CF) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CF) $(SRCS) -o $(NAME)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)


re		:	fclean	all
			rm -f $(OBJ) #delete

.PHONY	:	all clean fclean re