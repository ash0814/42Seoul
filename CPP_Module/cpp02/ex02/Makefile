NAME	=	Fixed

CC		=	c++ -Wall -Wextra -Werror
SRC		=	main.cpp Fixed.cpp

OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

%.o		:	./%.cpp
			$(CC) -c $<  -o $@

$(NAME)	:	$(OBJ)
	$(CC) $(SRC) -o $(NAME)
	make clean

clean	:	
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	: 	all clean fclean re
