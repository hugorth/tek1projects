/*
** EPITECH PROJECT, 2023
** atoi
** File description:
** atoi
*/

#include "my.h"

int my_atoi(char *str)
{
    int val;
    val = 0;
    for (; *str; str++) {
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        } else
            return (val);
    }
    return (val);
}

size_t my_strlenn(const char *const str)
{
    if (str == NULL) {
        return 0;
    }
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
