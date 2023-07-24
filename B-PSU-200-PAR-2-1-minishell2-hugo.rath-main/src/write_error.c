/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include <unistd.h>

int my_strlen(char const *str);

int write_error(char const *str)
{
    write(2, str, my_strlen(str));
    return 84;
}
