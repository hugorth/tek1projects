/*
** EPITECH PROJECT, 2023
** reverse_parcours.c
** File description:
** reverse parcours
*/

#include "dante.h"
#include "struct.h"

char print_map_charr(global_t *all)
{
    for (int i = 0; all->parsing->db_array[i]; i++) {
        if (i == all->parsing->height - 1) {
            write(1, all->parsing->db_array[i], all->parsing->width);
        } else {
            write(1, all->parsing->db_array[i], all->parsing->width);
            my_putchar('\n');
        }
    }
    return 0;
}

void reverse_parcours_suit(global_t *all, int i, int j)
{
    if (all->parsing->map[i][j] == 1) {
        all->parsing->db_array[i][j] = 'X';
    }
    if (all->parsing->map[i][j] == 0) {
        all->parsing->db_array[i][j] = '*';
    }
}

char **reverse_parcours(global_t *all)
{
    int row = all->parsing->height;
    int col = all->parsing->width;

    all->parsing->db_array = malloc(sizeof(char *) * (all->parsing->height));
    for (int i = 0; i < all->parsing->height; i++) {
        all->parsing->db_array[i] = malloc(sizeof(char) * all->parsing->width);
        for (int j = 0; j < all->parsing->width; j++) {
            reverse_parcours_suit(all, i, j);
        }
    }
    all->parsing->db_array[0][0] = 'o';
    road_trip(all, 0, 0);
    chek_k(all);
    print_map_charr(all);
}
