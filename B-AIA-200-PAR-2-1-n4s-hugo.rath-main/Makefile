##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

CC	=	gcc

SRC	=	src/main.c 			\
		src/detect_end.c 	\
		src/direction.c 	\
		src/ia.c 			\
		src/speed.c 		\
		src/extract_word.c	\
		src/my_str_to_wordtab.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

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
