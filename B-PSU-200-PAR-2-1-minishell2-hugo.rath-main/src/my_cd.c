/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"
extern char **environ;

void env1(char *value, char **env, int i, char *const name)
{
    if (value != NULL) {
        my_strcpy(value, env[i] + my_strlen(name) + 1);
    }
}

char *my_getenv(char *const name)
{
    size_t name_len = my_strlen(name);

    for (char **env = environ; *env; ++env) {
        if (my_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=') {
            return *env + name_len + 1;
        }
    }

    return NULL;
}

char *get_cd_path(mysh_t *minish)
{
    char *path = minish->args[1];
    char *home = my_getenv("HOME");
    minish->oldpwd = my_getenv("PWD");

    if (path == NULL) {
        path = home;
    } if (path[0] == '-' && path[1] == '\0') {
        path = minish->oldpwd;
    } if (path[0] == '~') {
        char *new_path = malloc(my_strlen(home) + my_strlen(path));
        if (new_path == NULL) {
            perror("malloc");
            return NULL;
        }
        my_strcpy(new_path, home);
        my_strcat(new_path, path + 1);
        path = new_path;
    } return path;
}

int change_directory(mysh_t *minish, char *path)
{
    if (chdir(path) == -1) {
        my_putstr(path);
        my_putstr(": Not a directory.\n");
        return -1;
    } else {
        char *pwd = getcwd(NULL, 0);
        if (pwd == NULL) {
            perror("getcwd");
            return -1;
        }
        minish->env[1] = pwd;
    }
    return 0;
}

int my_cd(mysh_t *minish)
{
    char *path = get_cd_path(minish);
    if (path == NULL)
        return -1;
    int result = change_directory(minish, path);
    return result;
}
