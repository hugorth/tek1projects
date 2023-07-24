/*
** EPITECH PROJECT, 2023
** strcat
** File description:
** strcat
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int nbr = 0;
    char *end = malloc(my_strlen(dest) + my_strlen(src) + 1);

    for (; dest[nbr] != '\0'; nbr++)
        end[nbr] = dest[nbr];
    for (int i = 0; src[i] != '\0'; i++, nbr++)
        end[nbr] = src[i];
    end[nbr] = '\0';
    return (end);
}
