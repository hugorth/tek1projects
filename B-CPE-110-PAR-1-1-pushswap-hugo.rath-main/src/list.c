/*
** EPITECH PROJECT, 2022
** list.c
** File description:
** list
*/
#include "../include/pushswap.h"

int *list_a(int ac, char **av)
{
    int *list_a = malloc(sizeof(int) * (ac - 1));
    int x = 1;

    for (int i = 0; i != ac - 1; i++) {
        list_a[i] = my_getnbr(av[x]);
        x++;
    }
    return list_a;
}

int *list_b(int ac)
{
    int *list_b = malloc(sizeof(int) * (ac - 1));
    return list_b;
}

list_s init_pushswap(list_s *list, int ac, char **av)
{
    list->list_a = list_a(ac, av);
    list->list_b = list_b(ac);
    list->size_a = ac - 1;
    list->size_b = 0;
    list->next = 0;

    return *list;
}
