/*
** EPITECH PROJECT, 2023
** setenvpart1
** File description:
** oui
*/

#include "my.h"

int split(mysh_t *sh, int i, int temp)
{
    for (int j = 0; sh->env[i][j] != '\0'; j++) {
        if (sh->env[i][j] != sh->args[1][j])
            break;
        if (sh->env[i][j] == sh->args[1][j] && sh->env[i][j + 1] == '=')
            temp = i;
    }
    return temp;
}

void split1(mysh_t *sh, int nbr)
{
    if (sh->args[2] != NULL)
        sh->env[nbr] = my_strcat(sh->env[nbr], sh->args[2]);
}

int isnt_dir(struct stat st, char *name)
{
    if (S_ISDIR(st.st_mode)) {
        write_error(name);
        write_error(": Permission denied.\n");
        free(name);
        return TRUE;
    }
    return 0;
}

bool check_first_char(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool check_args(char **args)
{
    if (check_first_char(args[1][0])) {
        if (check_alphanumeric(args[1])) {
            return true;
        } else {
            return false;
        }
    }
    write_error("setenv: Variable name must\n");
    write_error("begin with a letter.\n");
    return true;
}
