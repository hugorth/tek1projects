/*
** EPITECH PROJECT, 2023
** check_command
** File description:
** check
*/

#include "my.h"

static void command(mysh_t *sh, int nbr)
{
    if (nbr == 0)
        my_cd(sh);
    if (nbr == 1)
        get_env(sh);
    if (nbr == 2)
        my_setenv(sh);
    if (nbr == 3)
        my_unsetenv(sh);
    if (nbr == 4)
        my_exit(sh);
}

static char **fill_commands(char **commands)
{
    commands[0] = "cd\0";
    commands[1] = "env\0";
    commands[2] = "setenv\0";
    commands[3] = "unsetenv\0";
    commands[4] = "exit\0";
    commands[5] = NULL;
    return commands;
}

void error_command(mysh_t *sh, int nbr)
{
    if (nbr == 5) {
        if (exec_bin(sh))
            return;
        if (exec_prog(sh))
            return;
        write_error(sh->args[0]);
        write_error(": Command not found.\n");;
        return;
    }
}

void check_command(mysh_t *sh)
{
    char **commands = malloc(sizeof(char *) * 6);
    int nbr = 0;

    commands = fill_commands(commands);
    for (nbr = 0; nbr != 5; nbr++) {
        if (my_strcmp(sh->args[0], commands[nbr]))
            break;
    }
    free(commands);
    error_command(sh, nbr);
    command(sh, nbr);
    return;
}
