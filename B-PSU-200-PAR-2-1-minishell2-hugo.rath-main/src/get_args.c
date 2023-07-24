/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include <stdlib.h>
#include "my.h"

int count_args(char *buff, char sep)
{
    int nbr = 1;

    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == sep)
            nbr++;
    return (nbr);
}

void arg_space(mysh_t *sh, char *buff)
{
    char *ptr = buff;
    int j = 0, z = 0;

    while (*ptr != '\0') {
        if (*ptr == ' ') {
            sh->args[j][z] = '\0';
            ptr++;
            j++;
            z = 0;
        } else {
            sh->args[j][z] = *ptr;
            ptr++;
            z++;
        }
    }
    sh->args[j][z] = '\0';
}

void get_args(mysh_t *sh, char *buff)
{
    int nbr = count_args(buff, ' ');

    sh->args = malloc(sizeof(char *) * (nbr + 1));
    for (int i = 0; i != nbr; i++)
        sh->args[i] = malloc(sizeof(char) * (my_strlen(buff) + 1));
    arg_space(sh, buff);
    sh->args[nbr] = NULL;
    sh->first = nbr;
}
