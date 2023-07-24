/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** display.c
*/

#include "lemin.h"
#include "my.h"

void display_lineptr(char *lineptr)
{
    char *str = without_comments(lineptr);

    my_putstr(str);
    for (int i = 0; lineptr[i]; i++) {
        if (lineptr[i] == '#')
            my_putchar('\n');
    }
}

void display_room(lem_in_t *lem_in)
{
    if (lem_in == NULL)
        return;

    room_t *room = lem_in->first;

    while (room != NULL) {
        my_putstr("name :");
        my_putstr(room->name);
        my_putstr(", extremum:");
        my_putstr(room->extremum);
        my_putstr(", pos_x:");
        my_put_nbr(room->pos_x);
        my_putstr("pos_y:");
        my_put_nbr(room->pos_y);
        my_putstr("status:");
        my_put_nbr(room->status);
        my_putchar('\n');
        room = room->next;
    }
}

void display_link(lem_in_t *lem_in)
{
    if (lem_in == NULL)
        return;

    link_t *link = lem_in->first_link;

    while (link != NULL) {
        my_putstr(link->first_room);
        my_putchar('-');
        my_putstr(link->second_room);
        my_putchar('\n');
        link = link->next;
    }
}
