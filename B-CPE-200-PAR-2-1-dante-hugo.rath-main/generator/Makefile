##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

CC	=	gcc

SRC	=	main.c 			\
		generate_maze.c	\
		place_random.c 	\




OBJ	=	$(SRC:.c=.o)

NAME	=	generator

CFLAGS =	-Wall -Wextra

CPPFLAGS	=	-I./include

all:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS) -g

clean:
	$(RM) -f $(OBJ)
	$(RM) -f *~

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
