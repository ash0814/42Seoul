.PHONY : all clean fclean re
TARGET = BSQ
CC = gcc
CF= -Wall -Wextra -Werror
INC= ./
SRC  =  main.c base_function.c file_read.c ft_string.c numbers.c solution.c solution_help.c validate.c
OBJ=  $(SRC:.c=.o)
all :$(TARGET)
$(TARGET) :$(SRC)
    $(CC) $(CF) $(SRC) -o $@
clean : rm -f $(OBJ)
fclean : clean
    rm -f $(TARGET)
re  :  fclean all
