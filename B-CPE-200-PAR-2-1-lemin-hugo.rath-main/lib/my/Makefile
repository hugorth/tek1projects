##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compile all the lib
##

CC 	= 	gcc

SRC	=	*.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS   =       -Wall -Wextra

all:	$(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)
	cp my.h ../../include

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
