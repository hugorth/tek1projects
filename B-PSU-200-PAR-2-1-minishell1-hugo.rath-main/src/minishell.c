/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"

static void gest_eof(mysh_t *sh)
{
    my_putstr("exit\n");
    free(sh->buff);
    return;
}

void minishell(mysh_t *sh)
{
    long unsigned size = 10;

    sh->buff = malloc(sizeof(char) * size);
    my_putstr("$> ");
    if (getline(&sh->buff, &size, stdin) == EOF)
        return (gest_eof(sh));
    if (check_str(sh->buff) == NULL)
        minishell(sh);
    check_line(sh);
    minishell(sh);
}
