/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** find.c
*/

#include "lemin.h"
#include "my.h"

char *without_comments(char *lineptr)
{
    int i = 0;
    int y = 0;
    int nbr_space = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(lineptr) + 1));
    char *stock = 0;

    for (i = 0; lineptr[i] != '\0' && lineptr[i] != '#'; i++)
        tmp[i] = lineptr[i];
    tmp[i] = '\0';
    i--;
    while (i > 0 && lineptr[i] == ' ') {
        nbr_space++;
        i--;
    }
    stock = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    for (y = 0; y < (my_strlen(tmp) - nbr_space); y++)
        stock[y] = tmp[y];
    stock[y] = '\0';
    return stock;
}

int find_tunnel(char *lineptr)
{
    char *clean_lineptr = without_comments(lineptr);
    char **lineptr_array = my_str_to_word_array(clean_lineptr);
    int count_dash = 0;
    int nbr_param = 0;
    int count_space = 0;

    for (int i = 0; clean_lineptr[i] != '\0'; i++) {
        if (clean_lineptr[i] == '-')
            count_dash++;
        if (clean_lineptr[i] == ' ')
            count_space++;
    } if (count_dash != 1)
        return ERROR;
    for (nbr_param = 0; lineptr_array[nbr_param] != NULL; nbr_param++);
    if (nbr_param == 2 && count_space == 0)
        return SUCCES;
    return ERROR;
}

int find_room(char *lineptr)
{
    char *clean_lineptr = without_comments(lineptr);
    char **lineptr_array = my_str_to_word_array(clean_lineptr);
    int count_dash = 0;
    int nbr_param = 0;
    int count_space = 0;

    for (int i = 0; clean_lineptr[i] != '\0'; i++) {
        if (clean_lineptr[i] == '-')
            count_dash++;
        if (clean_lineptr[i] == ' ')
            count_space++;
    } if (count_dash > 0)
        return ERROR;
    for (nbr_param = 0; lineptr_array[nbr_param] != NULL; nbr_param++);
    if (nbr_param == 3 && count_space == 2)
        return SUCCES;
    return ERROR;
}
