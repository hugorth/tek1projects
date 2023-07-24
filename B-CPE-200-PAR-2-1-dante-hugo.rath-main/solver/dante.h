/*
** EPITECH PROJECT, 2023
** dante.h
** File description:
** all protypes and functions
*/

#ifndef DANTE_H_
    #define DANTE_H_

    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <stdio.h>
    #include "struct.h"
    #include <stdbool.h>
    #include <SFML/Graphics.h>

    int chek_files(int file);
    int chek_vals(char *str);
    int chek_all(global_t *all, char *str);

    void my_putchar(char c);
    int my_putstr(char const *str);
    int my_put_nbr(int nb);
    int my_strlen(char const *str);
    int my_strcmp(char const *s1, char const *s2);

    int count_col(char const *str);
    int count_row(char const *str);

    global_t *init_all(global_t *all, char *filepath);

    int len_file(char const *filepath);
    char *open_file(char const *filepath);

    int print_map_intt(global_t *all);
    void parcours_intt_suit(global_t *all, int i, int j);
    int **parcours_intt(global_t *all);

    char print_map_charr(global_t *all);
    void reverse_parcours_suit(global_t *all, int i, int j);
    char **reverse_parcours(global_t *all);

    int alphanumeric(char c);
    int words_str(char const *str);
    int *count_len_word(char const *str);
    char **array_double(char *str);

    int can_move_right(global_t *all, int row, int col);
    int can_move_left(global_t *all, int row, int col);
    int can_move_up(global_t *all, int row, int col);
    int can_move_down(global_t *all, int row, int col);

    int chek_k(global_t *all);
    int final_destination(global_t *all, int row, int col);
    int chek_neighbours(global_t *all, int row, int col);
    int road_trip(global_t *all, int row, int col);

#endif
