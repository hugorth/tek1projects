/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** manage.c
*/

#include "lemin.h"
#include "my.h"

int manage_tunnel(char *lineptr, lem_in_t *lem_in)
{
    if (lem_in->status == TUNNEL) {
        if (find_tunnel(lineptr) == ERROR && find_room(lineptr) == SUCCES) {
            lem_in->nbr_status_change++;
            lem_in->status = ROOM;
            add_room(without_comments(lineptr), lem_in);
        } if (find_tunnel(lineptr) == SUCCES)
            add_tunnel(without_comments(lineptr), lem_in);
        if (find_tunnel(lineptr) == ERROR && find_room(lineptr) == ERROR)
            return ERROR;
        display_lineptr(lineptr);
        return SUCCES;
    }
    return SUCCES;
}

void manage_room(char *lineptr, lem_in_t *lem_in)
{
    if (lem_in->status == ROOM) {
        if (find_room(lineptr) == ERROR && find_tunnel(lineptr) == SUCCES) {
            lem_in->nbr_status_change++;
            lem_in->status = TUNNEL;
            add_tunnel(without_comments(lineptr), lem_in);
        } if (find_room(lineptr) == SUCCES)
            add_room(without_comments(lineptr), lem_in);
        if (find_room(lineptr) == ERROR && find_tunnel(lineptr) == ERROR)
            lem_in->error = ERROR;
        display_lineptr(lineptr);
    }
    if (manage_tunnel(lineptr, lem_in) == ERROR)
        lem_in->error = ERROR;
}
