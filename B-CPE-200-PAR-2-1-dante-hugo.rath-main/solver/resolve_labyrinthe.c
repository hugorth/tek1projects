/*
** EPITECH PROJECT, 2023
** resolve_labyrithe.c
** File description:
** parcours the labyrithe
*/

#include "dante.h"
#include "struct.h"

void chek_k_suit(global_t *all, int i, int j)
{
    if (all->parsing->db_array[i][j] == 'k') {
        all->parsing->db_array[i][j] = '*';
    }
}

int chek_k(global_t *all)
{
    for (int i = 0; i < all->parsing->height; i++) {
        for (int j = 0; j < all->parsing->width; j++) {
            chek_k_suit(all, i, j);
        }
    }
    return 0;
}

int final_destination(global_t *all, int row, int col)
{
    return (row == all->parsing->height - 1 && col == all->parsing->width - 1);
}

int chek_neighbours(global_t *all, int row, int col)
{
    all->parsing->db_array[row][col] = 'o';
    if (can_move_right(all, row, col) ||
    can_move_down(all, row, col) ||
    can_move_left(all, row, col) ||
    can_move_up(all, row, col)) {
        return 1;
    }
    all->parsing->db_array[row][col] = 'k';
    return 0;
}

int road_trip(global_t *all, int row, int col)
{
    if (final_destination(all, row, col)) {
        return 1;
    }
    return chek_neighbours(all, row, col);
}
