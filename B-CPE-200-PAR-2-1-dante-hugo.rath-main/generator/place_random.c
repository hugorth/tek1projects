/*
** EPITECH PROJECT, 2023
** place random
** File description:
** place random
*/

#include "my.h"

void generate_map_struct(map_t *map)
{
    for (int i = 0; i != map->width; i++) {
        map->map[i] = malloc(sizeof(char) * map->height + 1);
        for (int j = 0; j != map->height; j++)
            map->map[i][j] = 'X';
        map->map[i][map->height] = '\0';
    }
}

void place_random_imperfect(map_t *map)
{
    int random = rand () % map->height + map->height / 5;
    for (int i = 1; i < map->width - 1; i += 2) {
        for (int j = random, k = 0; k != j; k++)
        map->map[i][rand() % map->height] = '*';
    }
}

void place_random_perfect(map_t *map)
{
    for (int i = 1; i < map->width - 1; i += 2)
        map->map[i][rand () % map->height] = '*';
}
