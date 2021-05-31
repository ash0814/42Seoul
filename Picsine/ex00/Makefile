CC = gcc
CF = -Wall -Wextra -Werror
INC = -I ./include/

TARGET = rush-02

SRCS = rush.c

OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CF) $(INC) -o $(TARGET) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(CF) $(INC) -c $(SRCS) -o $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET) 
