/*
** EPITECH PROJECT, 2023
** oui
** File description:
** oui
*/

#include "my.h"

static void check_semi(mysh_t *sh)
{
    int i = 0;
    while (sh->buff[i] != '\0') {
        if (sh->buff[i] == ';')
            sh->mode = 1;
        i++;
    }
}

static void free_args(char **args)
{
    int i = 0;
    while (args[i] != NULL) {
        free(args[i]);
        i++;
    }
    free(args);
}

void init_struct(mysh_t *sh)
{
    sh->mode = 0;
    sh->first = 0;
    sh->b = 0;
    sh->buff = trim_spaces(sh->buff);
}

void redirec(mysh_t *sh)
{
    int i = 0;
    if (sh->mode == 1) {
        get_the_buffers(sh);
        while (i != sh->b) {
            get_args(sh, sh->str[i]);
            check_command(sh);
            free_args(sh->args);
            i = i + 1;
        }
    }
}

void check_line(mysh_t *sh)
{
    init_struct(sh);
    check_semi(sh);
    if (sh->mode == 0) {
        get_args(sh, sh->buff);
        check_command(sh);
        free_args(sh->args);
    }
    redirec(sh);
}
