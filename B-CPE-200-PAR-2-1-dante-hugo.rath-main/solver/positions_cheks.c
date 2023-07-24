/*
** EPITECH PROJECT, 2023
** positions_cheks.c
** File description:
** verify les cases si elles sont libres
*/

#include "dante.h"
#include "struct.h"

int can_move_right(global_t *all, int row, int col)
{
    if (col + 1 < all->parsing->width &&
    all->parsing->db_array[row][col + 1] == '*') {
        all->parsing->db_array[row][col + 1] = 'o';
        if (road_trip(all, row, col + 1)) {
            return 1;
        }
    }
    return 0;
}

int can_move_left(global_t *all, int row, int col)
{
    if (col - 1 > - 1 &&
    all->parsing->db_array[row][col - 1] == '*') {
        all->parsing->db_array[row][col - 1] = 'o';
        if (road_trip(all, row, col - 1)) {
            return 1;
        }
    }
    return 0;
}

int can_move_up(global_t *all, int row, int col)
{
    if (row - 1 > - 1 &&
    all->parsing->db_array[row - 1][col] == '*') {
        all->parsing->db_array[row - 1][col] = 'o';
        if (road_trip(all, row - 1, col)) {
            return 1;
        }
    }
    return 0;
}

int can_move_down(global_t *all, int row, int col)
{
    if (row + 1 < all->parsing->height &&
    all->parsing->db_array[row + 1][col] == '*') {
        all->parsing->db_array[row + 1][col] = 'o';
        if (road_trip(all, row + 1, col)) {
            return 1;
        }
    }
    return 0;
}
