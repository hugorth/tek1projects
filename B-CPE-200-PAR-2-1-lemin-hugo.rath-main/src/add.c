/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** add.c
*/

#include "lemin.h"
#include "my.h"

void add_room(char *lineptr, lem_in_t *lem_in)
{
    room_t *new = malloc(sizeof(room_t));
    if (lem_in == NULL || new == NULL)
        return;
    new->extremum = extract_extremum(lineptr, lem_in);
    new->name = extract_name(lineptr);
    new->pos_x = extract_pos_x(lineptr);
    new->pos_y = extract_pos_y(lineptr);
    new->status = 0;

    new->next = lem_in->first;
    lem_in->first = new;
}

void add_tunnel(char *lineptr, lem_in_t *lem_in)
{
    link_t *new = malloc(sizeof(link_t));
    if (lem_in == NULL || new == NULL)
        return;
    new->first_room = extract_first_room(lineptr);
    new->second_room = extract_second_room(lineptr);
    new->next = lem_in->first_link;
    lem_in->first_link = new;
}

void add_start_end(char *lineptr, lem_in_t *lem_in)
{
    if (lem_in->status_end == 1) {
        lem_in->end_line = without_comments(lineptr);
        lem_in->status_end = 0;
    } if (lem_in->status_start == 1) {
        lem_in->start_line = without_comments(lineptr);
        lem_in->status_start = 0;
    }
}
