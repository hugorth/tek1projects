/*
** EPITECH PROJECT, 2022
** ra_rb.c
** File description:
** ra_rb
*/

#include "../include/pushswap.h"

list_s ra_do(list_s *list)
{
    int tmp = 0;
    int a = 0;

    tmp = list->list_a[0];
    for (; a < list->size_a - 1; a++) {
        list->list_a[a] = list->list_a[a + 1];
    }
    list->list_a[a] = tmp;
    my_putstr("ra ");
    return *list;
}

list_s rb_do(list_s *list)
{
    int tmp = 0;
    int a = 0;

    tmp = list->list_b[0];
    for (; a < list->size_b - 1; a++) {
        list->list_b[a] = list->list_b[a + 1];
    }
    list->list_b[a] = tmp;
    my_putstr("rb ");
    return *list;
}
