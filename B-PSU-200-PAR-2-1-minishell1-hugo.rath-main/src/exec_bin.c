/*
** EPITECH PROJECT, 2023
** oui
** File description:
** oui
*/

#include "my.h"

static char **put_command(char **paths, char *command)
{
    for (int i = 0; paths[i] != NULL; i++) {
        paths[i] = my_strcat(paths[i], "/");
        paths[i] = my_strcat(paths[i], command);
    }
    return paths;
}

int path_null(char **paths, int i)
{
    if (paths[i] == NULL)
        return (FALSE);
    return 0;
}

void exec(int status, mysh_t *sh, char **paths, int i)
{
    if ((status = fork()) == 0)
        execve(paths[i], sh->args, sh->env);
    wait(&status);
}

int exec_bin(mysh_t *sh)
{
    char **paths = get_path(sh->env, "PATH");
    int i = 0;
    int status = 0;

    if (paths == NULL)
        return FALSE;
    paths = put_command(paths, sh->args[0]);
    for (i = 0; paths[i] != NULL; i++)
        if (access(paths[i], F_OK) != -1) {
            break;
        }
    if (access(paths[i], F_OK) == -1) {
        write_error(sh->args[0]);
        write_error(": Command not found.\n");
    }
    path_null(paths, i);
    exec(status, sh, paths, i);
    return TRUE;
}
