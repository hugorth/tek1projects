/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/
#include "../include/pushswap.h"

int check(list_s *list)
{
    int i = 0;

    while (i != list->size_a) {
        if (list->list_a[i] < list->list_a[i - 1])
            return -1;
        ++i;
    }
    return 0;
}

int error_handling(int ac)
{
    if (ac == 1)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    list_s *list = malloc(sizeof(list_s));

    *list = init_pushswap(list, ac, av);
    error_handling(ac);
    if (check(list) != -1)
        my_putchar('\n');
    else {
        *list = pushswap(list);
        my_putchar('\n');
        return 0;
    }
}
