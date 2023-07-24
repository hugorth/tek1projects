/*
** EPITECH PROJECT, 2023
** lib
** File description:
** str dup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * len + 1);

    for (int i = 0 ; i < len ; i++)
        str[i] = src[i];
    str[len] = '\0';
    return str;
}
