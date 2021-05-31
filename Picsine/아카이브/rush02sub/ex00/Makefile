CC = gcc
CF = -Wall -Wextra -Werror
INC = -I ./includes/

TARGET = rush-02

SRC = main.c util.c printval.c ft_putchar.c
SRC_DIR = ./srcs/
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = main.o util.o printval.o ft_putchar.o
OBJ_DIR = ./objs/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))


all : $(TARGET)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CF) $(INC) -c $< -o $@

$(TARGET) : $(OBJS)
	$(CC) $(CF) -o $(TARGET) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET) 
