/*
** EPITECH PROJECT, 2022
** pushswap.c
** File description:
** pushswap
*/

#include "../include/pushswap.h"

int small_nbr(list_s *list)
{
    int nb = list->list_a[0];
    int a = 0;

    while (a != list->size_a) {
        if ((list->list_a[a] < 0 && list->list_a[a] < nb) ||
            list->list_a[a] < nb)
            nb = list->list_a[a];
        ++a;
    }
    return nb;
}

list_s first_of_list(list_s *list)
{
    int nb = small_nbr(list);

    while (list->list_a[0] != nb) {
        *list = ra_do(list);
    }
    return *list;
}

list_s pushswap(list_s *list)
{
    int size = list->size_a;
    int i = 0;

    if (list < 0 && size == 1)
        return;
    if (size == 2) {
        *list = sa_do1(list);
        return;
    }
    while (i != size) {
        *list = first_of_list(list);
        *list = pb_do(list);
        i++;
    }
    for (int i = 0; i != size - 1; i++) {
        *list = pa_do(list);
    }
    *list = pa1_do(list);
    return *list;
}
