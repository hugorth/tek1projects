/*
** EPITECH PROJECT, 2022
** rra_rrb.c
** File description:
** rra_rrb
*/

#include "../include/pushswap.h"

list_s rra_do(list_s *list)
{
    int tmp = 0;
    int a = 0;

    tmp = list->list_a[list->size_a - 1];
    a = list->list_a[list->size_a - 1];

    for (; a > 0; a--) {
        list->list_a[a] = list->list_a[a - 1];
    }
    list->list_a[0] = tmp;
    my_putstr("rra ");
    return *list;
}

list_s rrb_do(list_s *list)
{
    int tmp = 0;
    int a = 0;

    tmp = list->list_b[list->size_b - 1];
    a = list->list_b[list->size_b - 1];

    for (; a > 0; a--) {
        list->list_b[a] = list->list_b[a - 1];
    }
    list->list_b[0] = tmp;
    my_putstr("rrb ");
    return *list;
}
