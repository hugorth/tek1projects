/*
** EPITECH PROJECT, 2022
** sa_sb.c
** File description:
** sa_sb
*/

#include "../include/pushswap.h"

list_s sa_do(list_s *list)
{
    int i = 0;

    if (list->size_a >= 2) {
        i = list->list_a[0];
        list->list_a[0] = list->list_a[1];
        list->list_a[1] = i;
        my_putstr("sa ");
    }
    return *list;
}

list_s sb_do(list_s *list)
{
    int i = 0;

    if (list->size_b >= 2) {
        i = list->list_b[0];
        list->list_b[0] = list->list_b[1];
        list->list_b[1] = i;
        my_putstr("sb ");
    }
    return *list;
}

list_s sa_do1(list_s *list)
{
    int i = 0;

    if (list->size_a >= 2) {
        i = list->list_a[0];
        list->list_a[0] = list->list_a[1];
        list->list_a[1] = i;
        my_putstr("sa");
    }
    return *list;
}
