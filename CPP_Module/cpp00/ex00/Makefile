NAME	=	megaphone

CXX		=	c++ -Wall -Wextra -Werror -std=c++98
SRC		=	megaphone.cpp

OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

%.o		:	./%.cpp
			$(CXX) -c $<  -o $@

$(NAME)	:	$(OBJ)
	$(CXX) $(SRC) -o $(NAME)
	make clean

clean	:	
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	: 	all clean fclean re
