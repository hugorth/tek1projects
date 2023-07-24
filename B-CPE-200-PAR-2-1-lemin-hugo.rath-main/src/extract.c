/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** extract.c
*/

#include "lemin.h"
#include "my.h"

char *extract_extremum(char *lineptr, lem_in_t *lem_in)
{
    char *extra = my_strdup("none");

    if (lem_in->end_line != 0
    && my_strcmp(lineptr, lem_in->end_line) == SUCCES)
        extra = my_strdup("end");
    if (lem_in->start_line != 0
    && my_strcmp(lineptr, lem_in->start_line) == SUCCES)
        extra = my_strdup("start");
    return extra;
}

char *extract_name(char *lineptr)
{
    char **array = my_str_to_word_array(lineptr);

    return array[0];
}

int extract_pos_x(char *lineptr)
{
    char *tmp = without_comments(lineptr);
    char **array = my_str_to_word_array(tmp);

    return (my_getnbr(array[1]));
}

int extract_pos_y(char *lineptr)
{
    char *tmp = without_comments(lineptr);
    char **array = my_str_to_word_array(tmp);

    return (my_getnbr(array[2]));
}
