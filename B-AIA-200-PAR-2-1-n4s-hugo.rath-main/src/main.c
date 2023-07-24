/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"

static void init_struct(n4s *sped)
{
    sped->left = 0;
    sped->mid = 0;
    sped->right = 0;
    sped->speed = 0.5;
    write(1, "START_SIMULATION\n", strlen("START_SIMULATION\n"));
}

int init_movement(n4s *sped)
{
    char *s = NULL;
    char **tab;

    while (1) {
        write(1, "GET_INFO_LIDAR\n", strlen("GET_INFO_LIDAR\n"));
        if (getline(&s, &(size_t){0}, stdin) == -1) {
            free(s);
            exit(0);
        } else if (detect_end(s)) {
            free(s);
            exit(0);
        }
        tab = my_str_to_wordtab(s, ":");
        free(s);
        if (strcmp(tab[1], "OK") == 0)
            launch_ia(sped, tab);
    }
    return (0);
}

int main(void)
{
    n4s sped;
    init_struct(&sped);
    char* s = NULL;
    size_t len = 0;
    ssize_t read = getline(&s, &len, stdin);
    if (read == -1) {
        free(s);
        exit(0);
    }
    if (detect_end(s)) {
        free(s);
        exit(0);
    }
    free(s);
    if (init_movement(&sped) != 0)
        return 84;
    return 0;
}
