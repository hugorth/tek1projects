/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef myh
    #define myh

    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include <string.h>

    typedef struct map_t {
        char **map;
        int height;
        int width;
        int perfect;
        int status;
    } map_t;

void generate_map_struct(map_t *map);
void place_random_imperfect(map_t *map);
void place_random_perfect(map_t *map);
void perfect_maze(map_t *map);
void imperfect_maze(map_t *map);
void generate_perfect(map_t *map);
void generate(map_t *map);
void init_generator(int ac, char **av, map_t *map);

#endif /* !myh */
