/*
** EPITECH PROJECT, 2023
** detect_speed
** File description:
** detect_speed
*/

#include "../include/my.h"

void set_speed(double value)
{
    char* s = NULL;
    size_t len = 0;

    write(1, "CAR_FORWARD:", strlen("CAR_FORWARD:"));
    dprintf(1, "%.2f", value);
    write(1, "\n", strlen("\n"));
    ssize_t read = getline(&s, &len, stdin);
    if (read == -1) {
        free(s);
        exit(0);
    } if (detect_end(s) == 1) {
        free(s);
        exit(0);
    }
    free(s);
}
