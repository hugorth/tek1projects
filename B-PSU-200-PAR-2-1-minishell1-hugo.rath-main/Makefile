##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

CC	=	gcc

SRC	=	src/main.c		\
		src/copy_env.c		\
		src/minishell.c		\
		src/check_str.c	\
		src/is_ok.c	\
		src/clean_argument.c	\
		src/get_str.c		\
		src/get_args.c		\
		src/check_command.c	\
		src/my_exit.c		\
		src/my_env.c		\
		src/my_setenv.c		\
		src/my_unsetenv.c	\
		src/my_cd.c		\
		src/exec_bin.c		\
		src/get_path.c		\
		src/exec_prog.c		\
		src/my_strcpy.c 	\
		src/write_error.c 	\
		src/my_strlen.c 	\
		src/my_putstr.c		\
		src/my_atoi.c 		\
		src/my_putchar.c 	\
		src/my_strcat.c 	\
		src/my_strcmp.c 	\
		src/mysetenv_part1.c 	\
		src/my_strncmp.c 	\
		src/check_setenv.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

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
