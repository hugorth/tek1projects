/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** number_of_ants.c
*/

#include "lemin.h"
#include "my.h"

int engine_moves(lem_in_t *lem_in)
{
    if (lem_in == NULL) {
        return 84;
    }
    return 0;
}


int getline_loop(char *lineptr, size_t size, lem_in_t *lem_in)
{
    while (getline(&lineptr, &size, stdin) != -1) {
        if (check_lines(lineptr) == ERROR)
            return ERROR;
        if (init_and_display(lineptr, lem_in) == ERROR)
            return ERROR;
    }
    if (check_parsing(lem_in) == ERROR || lem_in->nbr_status_change != 1
    || lem_in->error == ERROR)
        return ERROR;
    my_putstr("#moves\n");
    return SUCCES;
}

int number_of_ants(char *lineptr, size_t size)
{
    if (getline(&lineptr, &size, stdin) == -1)
        return FALSE;
    while (lineptr[0] == '#') {
        if (getline(&lineptr, &size, stdin) == -1)
            return FALSE;
    }
    if (check_ants_line(lineptr) == ERROR)
        return ERROR;
    my_putstr("#number_of_ants\n");
    my_put_nbr(my_atoi(lineptr));
    my_putstr("\n#rooms\n");
    return SUCCES;
}
