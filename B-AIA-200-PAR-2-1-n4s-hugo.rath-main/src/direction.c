/*
** EPITECH PROJECT, 2023
** detect_dir
** File description:
** detect_dir
*/

#include "../include/my.h"

void set_direction(double value, int neg)
{
    char* s = NULL;
    size_t len = 0;
    write(1, "WHEELS_DIR:", strlen("WHEELS_DIR:"));
    if (neg == 1)
        dprintf(1, "-");
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
