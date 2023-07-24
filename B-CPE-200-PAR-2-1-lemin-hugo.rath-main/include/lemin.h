/*
** EPITECH PROJECT, 2022
** lemin.h
** File description:
** make lemin.h
*/

#ifndef LEMIN_H
    #define LEMIN_H
    #define SUCCES 0
    #define FALSE 1
    #define ERROR 84
    #define EMPTY 0
    #define FULL 1

    #define ROOM 2
    #define TUNNEL 3

    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>

typedef struct link {
    char *first_room;
    char *second_room;
    struct link *next;
} link_t;

typedef struct room {
    char *extremum;
    char *name;
    int pos_x;
    int pos_y;
    int status;
    struct room *next;
} room_t;

typedef struct lem_in_s {
    int first_tunnels;
    char *end_line;
    char *start_line;
    int nbr_end;
    int nbr_start;
    int status_end;
    int status_start;
    int status;
    int nbr_status_change;
    int error;
    room_t *first;
    link_t *first_link;
} lem_in_t;

typedef struct path {
    char **rooms;
    struct path *next;
}path_t;


int number_of_ants(char *lineptr, size_t size);
lem_in_t *init_lem_in(void);
int getline_loop(char *lineptr, size_t size, lem_in_t *lem_in);
int init_and_display(char *lineptr, lem_in_t *lem_in);
int check_lines(char *lineptr);
int check_ants_line(char *lineptr);
int check_parsing(lem_in_t *lem_in);
int my_atoi(char *str);
void display_lineptr(char *lineptr);
int find_tunnel(char *lineptr);
int find_room(char *lineptr);
char *without_comments(char *lineptr);
char **my_str_to_word_array(char const *str);
int manage_tunnel(char *lineptr, lem_in_t *lem_in);
void manage_room(char *lineptr, lem_in_t *lem_in);
room_t *init_room(void);
void add_tunnel(char *lineptr, lem_in_t *lem_in);
void add_room(char *lineptr, lem_in_t *lem_in);
int extract_pos_y(char *lineptr);
int extract_pos_x(char *lineptr);
char *extract_name(char *lineptr);
char *extract_extremum(char *lineptr, lem_in_t *lem_in);
void display_room(lem_in_t *lem_in);
void display_link(lem_in_t *lem_in);
void check_start_end(char *lineptr, lem_in_t *lem_in);
void add_room(char *lineptr, lem_in_t *lem_in);
void add_tunnel(char *lineptr, lem_in_t *lem_in);
void add_start_end(char *lineptr, lem_in_t *lem_in);
link_t *init_link(void);
char *extract_first_room(char *lineptr);
char *extract_second_room(char *lineptr);
int engine_moves(lem_in_t *lem_in);
char ***find_path(lem_in_t *lem_in);

#endif /* !LEMIN_H */
