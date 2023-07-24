/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"

void get_env(mysh_t *sh)
{
    int i = 0;
    for (int i = 0; sh->env[i] != NULL; i++) {
        my_putstr(sh->env[i]);
        my_putchar('\n');
    }
}
