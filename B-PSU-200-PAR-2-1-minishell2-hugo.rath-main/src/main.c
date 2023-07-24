/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"

static void free_env(mysh_t *sh)
{
    for (int i = 0; sh->env[i] != NULL; i++)
        free(sh->env[i]);
    free(sh->env);
    free(sh);
}

int should_exit(const char* command)
{
    return my_strcmp1(command, "exit") == 0;
}

int main(int ac, char **av, char **envp)
{
    mysh_t *sh = malloc(sizeof(mysh_t));

    if (sh == NULL)
        return (write_error("Alloctation failed\n"));
    if (ac != 1 || av[0] == NULL)
        return 84;
    copy_env(sh, envp);
    minishell(sh);
    free_env(sh);
    return 0;
}
