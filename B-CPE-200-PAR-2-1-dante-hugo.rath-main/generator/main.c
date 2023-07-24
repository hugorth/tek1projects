/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "my.h"

void init_generator(int ac, char **av, map_t *map)
{
    map = malloc(sizeof(map_t));
    map->status = 0;
    if (ac == 3)
        map->perfect = 0;
    else if (ac == 4)
        map->perfect = 1;
    map->height = atoi(av[1]);
    map->width = atoi(av[2]);
    map->map = NULL;
    map->map = malloc(sizeof(char *) * map->width);
    generate_map_struct(map);
    srand(time(NULL));
    generate(map);
}

int error(int ac, char **av)
{
    if (ac < 3) {
        printf("not enough arguments\n");
        return 84;
    }
    if (strncmp(av[1], "0", 1) == 0 || strncmp(av[2], "0", 1) == 0) {
        printf("dimension need to me higher than 0\n");
        return 84;
    }
    if (!atoi(av[1]) || !atoi(av[2])) {
        printf("dimensions needs to be a number\n");
        return 84;
    }
    if (ac == 4)
        if (strcmp(av[3], "perfect")) {
            printf("enter correct option pls\n"); return 84;
        }
    if (strncmp(av[1], "-", 1) == 0 || strncmp(av[2], "-", 1) == 0) {
        printf("dimension cannot be negativ\n"); return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    map_t *map = 0;
    if (error(ac, av) == 84)
        return 84;
    if (ac == 3 || ac == 4)
        init_generator(ac, av, map);
    else if (ac > 4) {
        printf("too much arguments\n");
        return 84;
    } else {
        printf("not enough arguments\n");
        return 84;
    }
    return 0;
}
