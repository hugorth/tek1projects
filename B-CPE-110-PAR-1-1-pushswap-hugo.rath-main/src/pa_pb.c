/*
** EPITECH PROJECT, 2022
** pa_pb.c
** File description:
** pa_pb
*/

#include "../include/pushswap.h"

list_s pa_do(list_s *list)
{
    int tmp = 0;

    if (list->size_b > 0) {
        tmp = list->size_a;
        for (; tmp > 0; tmp--) {
            list->list_a[tmp] = list->list_a[tmp - 1];
        }
        list->size_a = list->size_a + 1;
        list->list_a[0] = list->list_b[0];
        tmp = 0;
        for (; tmp < list->size_b - 1; tmp++) {
            list->list_b[tmp] = list->list_b[tmp + 1];
        }
        list->list_b[list->size_b - 1] = 0;
        list->size_b = list->size_b - 1;
    }
    my_putstr("pa ");
    return *list;
}

list_s pa1_do1(list_s *list, int tmp)
{
    while (tmp < list->size_b - 1) {
        list->list_b[tmp] = list->list_b[tmp + 1];
        tmp++;
    }
    list->list_b[list->size_b - 1] = 0;
    list->size_b = list->size_b - 1;
    return *list;
}

list_s pa1_do(list_s *list)
{
    int tmp = 0;

    if (list->size_b > 0) {
        tmp = list->size_a;
        while (tmp > 0) {
            list->list_a[tmp] = list->list_a[tmp - 1];
            tmp--;
        }
        list->size_a = list->size_a + 1;
        list->list_a[0] = list->list_b[0];
        tmp = 0;
        pa1_do1(list, tmp);
    }
    my_putstr("pa");
    return *list;
}

list_s pb_do(list_s *list)
{
    int tmp = 0;

    if (list->size_a > 0) {
        tmp = list->size_b;
        for (; tmp > 0; tmp--) {
            list->list_b[tmp] = list->list_b[tmp - 1];
        }
        list->size_b = list->size_b + 1;
        list->list_b[0] = list->list_a[0];
        tmp = 0;
        for (; tmp < list->size_a - 1; tmp++) {
            list->list_a[tmp] = list->list_a[tmp + 1];
        }
        list->list_a[list->size_a - 1] = 0;
        list->size_a = list->size_a - 1;
    }
    my_putstr("pb ");
    return *list;
}
