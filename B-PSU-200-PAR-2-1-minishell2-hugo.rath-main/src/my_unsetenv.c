/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"

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

static char **del_elem(char **env, int nbr)
{
    int i = 0;

    env[nbr] = NULL;
    for (i = nbr; env[i + 1] != NULL; i++)
        env[i] = env[i + 1];
    env[i] = NULL;
    return (env);
}

int split3(mysh_t *sh, int temp, int i, char *arg)
{
    for (int j = 0; sh->env[i][j] != '\0'; j++) {
        if (sh->env[i][j] != arg[j])
            break;
        if (sh->env[i][j] == arg[j] && sh->env[i][j + 1] == '=')
            temp = i;
    }
    return temp;
}

static void remove_values(mysh_t *sh, char *arg)
{
    int temp = -1;

    for (int i = 0; sh->env[i] != NULL; i++)
        temp = split3(sh, temp, i, arg);
    if (temp == -1)
        return;
    sh->env = del_elem(sh->env, temp);
}

void my_unsetenv(mysh_t *sh)
{
    int i = 0;

    if (sh->first == 1) {
        write_error("unsetenv: Too few arguments.\n");
        return;
    }
    for (i = 0; sh->env[i] != NULL; i++);
    sh->env = realloc_env(sh->env, i);
    for (int j = 1; j != sh->first; j++)
        remove_values(sh, sh->args[j]);
}
