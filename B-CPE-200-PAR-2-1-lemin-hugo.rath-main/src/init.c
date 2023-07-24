/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** init.c
*/

#include "lemin.h"
#include "my.h"

lem_in_t *init_lem_in(void)
{
    lem_in_t *lem_in = malloc(sizeof(lem_in_t));

    if (lem_in == NULL)
        return lem_in;
    lem_in->first_tunnels = 0;
    lem_in->end_line = 0;
    lem_in->start_line = 0;
    lem_in->nbr_end = 0;
    lem_in->nbr_start = 0;
    lem_in->status_end = 0;
    lem_in->status_start = 0;
    lem_in->status = ROOM;
    lem_in->nbr_status_change = 0;
    lem_in->first = init_room();
    lem_in->first_link = init_link();
    lem_in->error = 0;
    return lem_in;
}

link_t *init_link(void)
{
    link_t *link = malloc(sizeof(link_t));

    if (link == NULL)
        return link;
    link->first_room = my_strdup("none");
    link->second_room = my_strdup("none");
    link->next = NULL;
    return link;
}

room_t *init_room(void)
{
    room_t *room = malloc(sizeof(room_t));

    if (room == NULL)
        return room;
    room->extremum = my_strdup("none");
    room->name = my_strdup("none");
    room->pos_x = 0;
    room->pos_y = 0;
    room->status = 0;
    room->next = NULL;
    return room;
}

int init_and_display(char *lineptr, lem_in_t *lem_in)
{
    add_start_end(lineptr, lem_in);
    check_start_end(lineptr, lem_in);
    if (lineptr[0] >= '0' && lineptr[0] <= '9') {
        if (find_tunnel(lineptr) == SUCCES && lem_in->first_tunnels == 0) {
            my_putstr("#tunnels\n");
            lem_in->first_tunnels++;
        }
        manage_room(lineptr, lem_in);
    }
    return SUCCES;
}
