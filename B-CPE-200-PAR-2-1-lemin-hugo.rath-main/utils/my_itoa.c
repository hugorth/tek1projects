/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** my_itoa
*/

#include "lemin.h"
#include "my.h"

char *my_revstr(char *str)
{
    char box;
    int start = 0;
    int end = my_strlen(str) - 1;

    while (end > start) {
        box = str[start];
        str[start] = str[end];
        str[end] = box;
        end -= 1;
        start += 1;
    }
    return (str);
}

char *my_itoa(int nbr)
{
    int box = nbr;
    int i = 0;
    char *result;

    while (box != 0) {
        box = box / 10;
        i++;
    }
    result = malloc(sizeof(char) * (i + 1));
    result[i] = '\0';
    for (int j = 0; nbr != 0; ++j) {
        result[j] = (nbr % 10) + '0';
        nbr = nbr / 10;
    }
    return my_revstr(result);
}
