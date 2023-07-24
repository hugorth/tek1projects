##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	compil.c				\
		open_file.c				\
		str_word_array.c		\
		main.c					\
		count_cols_rows.c		\
		chek_errors.c			\
		init_all.c				\
		parcours_intt.c			\
		reverse_parcours.c		\
		positions_cheks.c		\
		resolve_labyrinthe.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS  =	-Wextra -g

all:		$(NAME)


$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(SRC) $(CFLAGS)
			find . -type f -name "*~" -delete -o -name "*#*" -delete

clean:
	$(RM) *.o $(RM) vgcore.*
	find . -type f -name "*~" -delete -o -name "*#*" -delete

fclean: 	clean
			$(RM) $(NAME)

re:		fclean all

tests_run:	$(CC) $(SRC) --coverage -lcriterion -o $(TNAME)

.PHONY:		all clean fclean re tests_run
