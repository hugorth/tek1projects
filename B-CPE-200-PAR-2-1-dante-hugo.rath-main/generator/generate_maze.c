/*
** EPITECH PROJECT, 2023
** gen maze
** File description:
** gen maze
*/

#include "my.h"

static void make_map(map_t *map)
{
    for (int i = 0; i < map->width - 1; i += 2) {
        for (int j = 0; j < map->height; j++) {
            map->map[i][j] = '*';
        }
    }
    if (map->perfect == 1)
        place_random_perfect(map);
    else if (map->perfect == 0)
        place_random_imperfect(map);
    if (map->width % 2 == 0)
        map->map[map->width - 1][map->height - 1] = '*';
}

void perfect_maze(map_t *map)
{
    if (map->width % 2 == 1) {
        for (int i = 0; i != map->height; i++) {
            map->map[map->width - 1][i] = '*';
        }
    }
    make_map(map);
}

void imperfect_maze(map_t *map)
{
    perfect_maze(map);
    int i = 0;
    while (i < map->width - 1) {
        printf("%s\n", map->map[i]);
        i++;
    }
    printf("%s", map->map[map->width - 1]);
}

void generate_perfect(map_t *map)
{
    perfect_maze(map);
    int i = 0;
    while (i < map->width - 1) {
        printf("%s\n", map->map[i]);
        i++;
    }
    printf("%s", map->map[map->width - 1]);
}

void generate(map_t *map)
{
    if (map->perfect)
        generate_perfect(map);
    else
        imperfect_maze(map);
}
