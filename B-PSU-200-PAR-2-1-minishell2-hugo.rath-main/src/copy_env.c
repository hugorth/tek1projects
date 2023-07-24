/*
** EPITECH PROJECT, 2023
** oui
** File description:
** oui
*/

#include "my.h"

void copy_env1(mysh_t *sh, char **envp, int i)
{
    for (int j = 0; j < i; j++) {
        size_t len = my_strlen(envp[j]);
        sh->env[j] = malloc(sizeof(char) * (len + 1));
        my_strcpy(sh->env[j], envp[j]);
    }
}

void copy_env(mysh_t *sh, char **envp)
{
    sh->env = NULL;
    int i = 0;
    for (; envp[i]; i++);
    sh->env = malloc(sizeof(char *) * (i + 1));
    copy_env1(sh, envp, i);
    sh->env[i] = NULL;
}
