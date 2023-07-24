/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** check.c
*/

#include "lemin.h"
#include "my.h"

int check_lines(char *lineptr)
{
    int count = 0;
    int i = 0;

    if (lineptr[0] == '#' && lineptr[1] != '#')
        return 0;
    for (i = 0; lineptr[i] != '\0'; i++) {
        if (lineptr[i] == ' ' || lineptr[i] == '-' || lineptr[i] == '\n'
        || lineptr[i] == '\0' || lineptr[i] == '#')
            count++;
        if (lineptr[i] >= '0' && lineptr[i] <= '9')
            count++;
        if ((lineptr[i] >= 'a' && lineptr[i] <= 'z')
        || (lineptr[i] >= 'A' && lineptr[i] <= 'Z'))
            count++;
    } if (count == i)
        return SUCCES;
    return ERROR;
}

int check_ants_line(char *lineptr)
{
    for (int i = 0; lineptr[i] != '\0'; i++) {
        if (lineptr[i] == '#' && lineptr[i + 1] != '#')
            break;
        if (lineptr[i] != ' ' && lineptr[i] != '\n'
        && (lineptr[i] < '0' || lineptr[i] > '9'))
            return ERROR;
    }
    return SUCCES;
}

int check_parsing(lem_in_t *lem_in)
{
    if (lem_in->nbr_end != 1 || lem_in->nbr_start != 1)
        return ERROR;
    return SUCCES;
}

void check_start_end(char *lineptr, lem_in_t *lem_in)
{
    if (my_strcmp(lineptr, "##end\n") == SUCCES) {
        if (lem_in->nbr_start == 0)
            lem_in->error = ERROR;
        lem_in->nbr_end++;
        lem_in->status_end++;
        my_putstr(lineptr);
    } if (my_strcmp(lineptr, "##start\n") == SUCCES) {
        lem_in->nbr_start++;
        lem_in->status_start++;
        my_putstr(lineptr);
    }
}
