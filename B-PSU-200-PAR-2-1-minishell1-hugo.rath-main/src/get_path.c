/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"

static int remove_value(char *path)
{
    int i = 0;

    for (i = 0; path[i] != '='; i++);
    i++;
    return i;
}

void get_path1(char *path, int i, char **sep)
{
    for (int j = 0, z = 0; path[i] != 0; i++, z++) {
        if (path[i] == ':') {
            sep[j][z] = '\0';
            i += 1;
            j += 1;
            z = 0;
        }
        if (path[i + 1] == '\0') {
            sep[j][z] = path[i];
            sep[j][z + 1] = '\0';
        }
        sep[j][z] = path[i];
    }
}

static char **separate_paths(char *path)
{
    int nbr = count_args(path, ':');
    char **sep = malloc(sizeof(char *) * (nbr + 1));
    int i = remove_value(path);

    for (int j = 0; j != nbr; j++)
        sep[j] = malloc(sizeof(char) * (my_strlen(path) + 1));
    get_path1(path, i, sep);
    sep[nbr] = NULL;
    return (sep);
}

int path(int i, char **env, int temp, char const *var)
{
    for (int j = 0; env[i][j] != '\0'; j++) {
        if (env[i][j] != var[j])
            break;
        if (env[i][j] == var[j] && env[i][j + 1] == '=')
            temp = i;
    }
    return temp;
}

char **get_path(char **env, char const *var)
{
    int temp = -1;
    char **paths;

    for (int i = 0; env[i] != NULL; i++)
        temp = path(i, env, temp, var);
    if (temp == -1)
        return (NULL);
    paths = separate_paths(env[temp]);
    return (paths);
}
