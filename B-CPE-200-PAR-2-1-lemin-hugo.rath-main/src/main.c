/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** main.c
*/

#include "lemin.h"
#include "my.h"

int main(void)
{
    char *lineptr = NULL;
    size_t size = 0;
    lem_in_t *lem_in = init_lem_in();

    if (number_of_ants(lineptr, size) == ERROR)
        return ERROR;
    if (getline_loop(lineptr, size, lem_in) == ERROR)
        return ERROR;
    if (engine_moves(lem_in) == ERROR)
        return ERROR;
    return SUCCES;
}
