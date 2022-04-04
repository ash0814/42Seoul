NAME	=	base

CXX		=	c++ -Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp A.cpp B.cpp C.cpp Base.cpp

OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

%.o		:	./%.cpp
			$(CXX) -c $< -o $@

$(NAME)	:	$(OBJ)
	$(CXX) $(SRC) -o $(NAME)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	: 	all clean fclean re