/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"

#include <stdbool.h>

static char **realloc_env(char **env, int nbr)
{
    char **new_env = malloc(sizeof(char *) * (nbr + 1));
    int i;

    for (i = 0; i < nbr && env[i] != NULL; i++) {
        new_env[i] = env[i];
    } if (i < nbr) {
        new_env[i] = NULL;
    }
    return new_env;
}

static void change_value(mysh_t *sh, int nbr)
{
    int temp = -1;

    for (int i = 0; sh->env[i] != NULL; i++)
        temp = split(sh, i, temp);
    if (temp == -1) {
        if (sh->first >= 2) {
            sh->env[nbr] = my_strcat(sh->args[1], "=");
            split1(sh, nbr);

        }
    }
    sh->env[temp] = my_strcat(sh->args[1], "=");
    if (sh->args[2] != NULL)
        sh->env[temp] = my_strcat(sh->env[temp], sh->args[2]);
}

void my_setenv(mysh_t *sh)
{
    int i = 0;

    if (sh->first > 4) {
        write_error("setenv: Too many arguments.\n");
    }
    if (sh->args[1] == NULL) {
        get_env(sh);
        return;
    }
    if (check_args(sh->args))
        return;
    while (sh->env[i] != NULL) {
        i += 1;
    }
    sh->env = realloc_env(sh->env, i);
    change_value(sh, i);
}
