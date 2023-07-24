/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** extra_link.c
*/

#include "lemin.h"
#include "my.h"

char *extract_first_room(char *lineptr)
{
    int i = 0;
    int y = 0;
    char *tmp = 0;

    for (i = 0; lineptr[i] != '\0' && lineptr[i] != '-'; i++);
    tmp = malloc(sizeof(char) * (i + 1));
    for (y = 0; lineptr[y] != '\0' && lineptr[y] != '-'; y++)
        tmp[y] = lineptr[y];
    tmp[y] = '\0';

    return tmp;
}

char *extract_second_room(char *lineptr)
{
    int i = 0;
    int y = 0;
    int j = 0;
    int z = 0;
    char *tmp = 0;

    for (i = 0; lineptr[i] != '\0' && lineptr[i] != '-'; i++);
    if (lineptr[i] == '-')
        i++;
    for (y = i; lineptr[y] != '\0'; y++);
    tmp = malloc(sizeof(char) * (y + 1));
    for (j = i, z = 0; lineptr[j] != '\0'; j++, z++)
        tmp[z] = lineptr[j];
    tmp[z] = '\0';
    return tmp;
}
