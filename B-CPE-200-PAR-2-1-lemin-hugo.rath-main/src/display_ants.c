/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** display_ants.c
*/

#include "lemin.h"
#include "my.h"

char *find_next_room(room_t *room, lem_in_t *lem_in)
{
    link_t *link = lem_in->first_link;

    while (my_strcmp(room->name, link->first_room) != SUCCES) {
        if (my_strcmp(link->first_room, "none") == SUCCES)
            return NULL;
        link = link->next;
    }
    return link->second_room;
}

void full_next_room(char *next_room, lem_in_t *lem_in, int ants_number)
{
    room_t *room = lem_in->first;

    while (room != NULL) {
        if (next_room != NULL && room->name != NULL
        && my_strcmp(next_room, room->name) == SUCCES) {
            room->status = FULL;
            room->ants_number = ants_number;
        }
        room = room->next;
    }
}

void display_moves_lines(char *name, int ants_number, int next_round)
{
    my_putchar('P');
    my_put_nbr(ants_number);
    my_putchar('-');
    my_putstr(name);
    if (ants_number == next_round)
        my_putchar('\n');
    else
        my_putchar(' ');
}

void display_ants(lem_in_t *lem_in)
{
    room_t *room = lem_in->first;
    char *next_room = 0;

    while (room != NULL) {
        if (room->status == FULL) {
            display_moves_lines(room->name
            , room->ants_number, lem_in->ants_nbr);
            room->status = EMPTY;
            next_room = find_next_room(room, lem_in);
            full_next_room(next_room, lem_in, room->ants_number);
        }
        room = room->next;
    }
}
