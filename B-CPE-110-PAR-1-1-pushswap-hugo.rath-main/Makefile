##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

CC	=	gcc

SRC	=	src/main.c 				\
		src/list.c 				\
		src/my_getnbr.c 		\
		src/my_putchar.c 		\
		src/my_putstr.c 		\
		src/pa_pb.c 			\
		src/sa_sb.c 			\
		src/rra_rrb.c 			\
		src/ra_rb.c 			\
		src/pushswap.c 			\
		src/my_put_nbr.c 		\

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

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
