/*
** EPITECH PROJECT, 2023
** struct.h
** File description:
** structures
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct double_s {
        char **db_array;
        int **map;
        int height;
        int width;
        int size;
    } double_t;

    typedef struct global_t {
        double_t *parsing;
    } global_t;
#endif
