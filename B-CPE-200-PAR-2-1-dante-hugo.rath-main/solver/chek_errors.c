/*
** EPITECH PROJECT, 2023
** chek_errors.c
** File description:
** detects all caracteres
*/

#include "dante.h"
#include "struct.h"

int chek_files(int file)
{
    if (file == -1) {
        return 84;
    }
    return 0;
}

int chek_vals(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '*' || str[i] == 'X' ||
            str[i] == '\0') {
            return 1;
        } else {
            return 84;
        }
        i++;
    }
    return 0;
}
