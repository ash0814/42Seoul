NAME	=	a.out

CXX		=	c++ -Wall -Wextra -Werror -std=c++98
SRC		=	Bureaucrat.cpp main.cpp Form.cpp\
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \
			PresidentialPardonForm.cpp \
			Intern.cpp

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
			rm -f *_shrubbery

re		:	fclean all

.PHONY	: 	all clean fclean re