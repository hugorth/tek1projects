/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"

static int check_path(char *arg, char **env)
{
    char **path = get_path(env, "PATH");

    if (path == NULL)
        return (FALSE);
    for (int i = 0; path[i] != NULL; i++)
        if (my_strcmp(path[i], arg))
            return TRUE;
    return FALSE;
}

static char *get_name(char *arg)
{
    char *name = malloc(sizeof(char) * (my_strlen(arg) + 1));

    for (int i = 0, j = 2; arg[j] != '\0'; i++, j++)
        name[i] = arg[j];
    return name;
}

int is_dir(mysh_t *sh, struct stat st)
{
    if (sh->args[0][0] != '.') {
        if (S_ISDIR(st.st_mode) || check_path(sh->args[0], sh->env)) {
            write_error(sh->args[0]);
            write_error(": Permission denied.\n");
            return TRUE;
        }
        return FALSE;
    }
    return 0;
}

static int check_if_dir(mysh_t *sh)
{
    char *name = get_name(sh->args[0]);
    struct stat st;

    is_dir(sh, st);
    stat(name, &st);
    isnt_dir(st, name);
    free(name);
    return (FALSE);
}

int exec_prog(mysh_t *sh)
{
    if (check_if_dir(sh))
        return TRUE;

    if (access(sh->args[0], F_OK) == -1)
        return FALSE;

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return FALSE;
    } else if (pid == 0) {
        execve(sh->args[0], sh->args, sh->env);
        perror("execve failed");
    } else {
        int status;
        waitpid(pid, &status, 0);
        return TRUE;
    }
    return 0;
}
