/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** finds all the paths
*/

#include "lemin.h"
#include "my.h"

static int get_tab_size(char **tab)
{
    int size = 0;

    for (; tab[size] != NULL; size++);
    return size + 1;
}

static char **add_to_path(char **path, char *room1)
{
    int size = get_tab_size(path);
    char **new_tab = malloc(sizeof(char *) * (size + 2));

    for (int i = 0; path[i] != NULL; i++) {
        new_tab[i] = my_strdup(path[i]);
        free(path[i]);
    }
    free(path);
    new_tab[size] = my_strdup(room1);
    new_tab[size + 1] = NULL;
    return new_tab;
}

void find_paths(lem_in_t *lem_in, path_t *first_path)
{
    link_t *links = lem_in->first_link;
    path_t *new_path = malloc(sizeof(path_t));
    char *tmp = my_strdup(lem_in->first->name);
    int stop = 0;

    new_path->rooms = malloc(sizeof(char *) * 2);
    new_path->rooms[0] = my_strdup(tmp);
    new_path->rooms[1] = NULL;
    while (links != NULL && my_strcmp(tmp, lem_in->end_line) == 0) {
        if (my_strcmp(tmp, links->first_room) != 0)
            links = links->next;
        new_path->rooms = add_to_path(new_path->rooms, links->second_room);
        tmp = my_strdup(links->second_room);
    }
    if (my_strcmp(links->second_room, lem_in->end_line) != 0)
        return;
    new_path->next = first_path;
}
