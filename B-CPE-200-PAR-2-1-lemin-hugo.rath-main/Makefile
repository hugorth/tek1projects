##
## EPITECH PROJECT, 2023
## lem-in
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c \
		src/number_of_ants.c \
		src/check.c \
		src/display.c \
		src/find.c \
		src/init.c \
		src/add.c \
		src/manage.c \
		src/extract.c \
		src/extra_link.c \
		utils/my_atoi.c \
		utils/my_str_to_word_array.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

LDFLAGS	=	-L./lib/my -lmy

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	$(MAKE) -C lib/my/ clean
	$(RM) -f $(OBJ)
	$(RM) -f *~

fclean: clean
	$(MAKE) -C lib/my/ fclean
	$(RM) -f $(NAME)

re: fclean all

debug: CPPFLAGS += -g3
debug: re

.PHONY: all clean fclean re
