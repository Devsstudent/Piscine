CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = rush-02 
SRCS = srcs/dict.c srcs/driver.c srcs/main.c srcs/utils.c	
OBJS = $(SRCS:.c=.o)

all :	$(NAME)

$(NAME): 
	$(CC) $(FLAGS) $(SRCS) -o $@

clean :
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
