/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** compil all fucntions
*/

#include "dante.h"
#include "struct.h"

int main(int ac, char **av, global_t *all)
{
    if (ac != 2) {
        return 84;
    } else {
        if (open_file(av[1]) != NULL) {
            init_all(all, av[1]);
        }
    }
    return 0;
}
