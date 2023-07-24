/*
** EPITECH PROJECT, 2023
** init_all.c
** File description:
** init all functions
*/

#include "dante.h"
#include "struct.h"

global_t *init_all(global_t *all, char *filepath)
{
    int status = 84;
    char *tab = open_file(filepath);
    if (chek_vals(tab) == 84) {
        exit(status);
    }
    all = malloc(sizeof(global_t));
    all->parsing = malloc(sizeof(double_t));
    all->parsing->height = count_row(tab);
    all->parsing->width = count_col(tab);
    all->parsing->db_array = array_double(tab);
    all->parsing->map = parcours_intt(all);
    all->parsing->size = len_file(filepath);
    parcours_intt(all);
    reverse_parcours(all);
}
