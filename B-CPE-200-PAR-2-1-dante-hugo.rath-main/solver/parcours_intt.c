/*
** EPITECH PROJECT, 2023
** parcours de map en int **
** File description:
** parcours_intt
*/

#include "dante.h"
#include "struct.h"

int print_map_intt(global_t *all)
{
    for (int i = 0; i < all->parsing->height; i++) {
        for (int j = 0; j < all->parsing->width; j++) {
            printf("%d", all->parsing->map[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void parcours_intt_suit(global_t *all, int i, int j)
{
    if (all->parsing->db_array[i][j] == 'X') {
        all->parsing->map[i][j] = 1;
    }
    if (all->parsing->db_array[i][j] == '*') {
        all->parsing->map[i][j] = 0;
    }
}

int **parcours_intt(global_t *all)
{
    all->parsing->map = malloc(sizeof(int *) * (all->parsing->height + 1));
    all->parsing->map[all->parsing->height] = NULL;

    for (int i = 0; i < all->parsing->height; i++) {
        all->parsing->map[i] = malloc(sizeof(int) * all->parsing->width);
        for (int j = 0; j < all->parsing->width; j++) {
            parcours_intt_suit(all, i, j);
        }
    }
}
