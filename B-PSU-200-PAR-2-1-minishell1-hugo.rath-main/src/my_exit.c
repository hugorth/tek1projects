/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"

static void free_all(mysh_t *sh)
{
    int i = 0;
    while (i < sh->first) {
        free(sh->args[i]);
        i++;
    }
    free(sh->args);
    while (i < sh->b) {
        free(sh->str[i]);
        i++;
    }
    free(sh->str);
    while (sh->env[i] != NULL) {
        free(sh->env[i]);
        i++;
    }
    free(sh->env);
    free(sh);
}

void my_exit(mysh_t *sh)
{
    if (sh->first > 2) {
        write_error("exit: Expression Syntax.\n");
        return;
    }

    int value = sh->first == 1 ? 0 : my_atoi(sh->args[1]);
    free_all(sh);
    exit(value);
}
