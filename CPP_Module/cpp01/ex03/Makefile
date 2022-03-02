NAME	=	Human

CXX		=	c++ -Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ		=	$(SRC:.cpp=.o)

all		:	$(NAME)

%.o		:	./%.cpp
			$(CXX) -c $<  -o $@

$(NAME)	:	$(OBJ)
	$(CXX) $(SRC) -o $(NAME)

clean	:	
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	: 	all clean fclean re
