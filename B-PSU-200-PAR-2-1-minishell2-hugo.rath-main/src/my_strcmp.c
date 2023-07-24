/*
** EPITECH PROJECT, 2022
** pool
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char *const str1, char *const str2)
{
    int i = 0;
    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    while (str1[i] != '\0') {
        if (str1[i] != str2[i])
            return 0;
        i++;
    }
    return 1;
}

int my_strcmp1(const char *str1, const char *str2)
{
    while (*str1 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}
