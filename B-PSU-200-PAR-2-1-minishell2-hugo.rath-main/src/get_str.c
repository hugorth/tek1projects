/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"

static int count_buffs(char *buff, char sep)
{
    int nbr = 1;

    for (int i = 0; buff[i] != '\0'; i++)
        nbr += (buff[i] == sep);
    return nbr;
}

void get_buff(mysh_t *sh, int j, int z)
{
    for (int i = 0; sh->buff[i] != '\0'; i++, z++) {
        if (sh->buff[i] == ';') {
            sh->str[j][z] = '\0';
            i++;
            j++;
            z = 0;
        }
        sh->str[j][z] = sh->buff[i];
    }
}

void get_the_buffers(mysh_t *sh)
{
    int j = 0;
    int z = 0;

    sh->b = count_buffs(sh->buff, ';');
    sh->str = malloc(sizeof(char *) * (sh->b + 2));
    for (int i = 0; i != sh->b; i++)
        sh->str[i] = malloc(sizeof(char) * (my_strlen(sh->buff) + 1));
    get_buff(sh, j, z);
    sh->str[j][z] = '\0';
    sh->str[sh->b + 1] = NULL;
    for (int i = 0; i != sh->b; i++)
        sh->str[i] = cleanstr(sh->str[i]);
}
