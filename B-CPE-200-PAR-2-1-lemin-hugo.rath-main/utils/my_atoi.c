/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** my_atoi.c
*/

#include "lemin.h"
#include "my.h"

int my_atoi(char *str)
{
    int pos = 0;
    int res = 0;

    while (str[pos] < '0' || str[pos] > '9') {
        pos++;
    } while (str[pos] >= '0' && str[pos] <= '9') {
        res = res * 10 + str[pos] - '0';
        pos++;
    } return res;
}
