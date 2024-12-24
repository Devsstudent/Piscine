CC=gcc
NAME=executable
CFLAGS=-Wall -Werror -Wextra
SOURCES= $(wildcard */*.c)
MAIN=$(wildcard main.c)
DEPS=main.h
OBJ=$(patsubst %.c,%.o,$(SOURCES))

all : $(NAME)

$(NAME) : $(OBJ) main.o
	$(CC) $(OBJ) main.o -o $(NAME)

main.o: $(MAIN)
	$(CC) -o  $@ -c $(MAIN) 

$(OBJ) : $(SOURCES) 
	$(CC) -o  $@ -c $< 

clean : 
	rm $(NAME)

re : 
	$(fclean) make all

fclean:
	$(clean) rm *.o */*.o
