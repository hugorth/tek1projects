/*
** EPITECH PROJECT, 2023
** count_cols_rows
** File description:
** count cols and count rows
*/

#include "dante.h"
#include "struct.h"

int count_row(char const *str)
{
    int row = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            row++;
        }
        i++;
    }
    return row;
}

int count_col(char const *str)
{
    int col = 0;
    int i = 0;
    while (str[i] != '\n') {
        col++;
        i++;
    }
    return col;
}
