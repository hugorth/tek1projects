/*
** EPITECH PROJECT, 2023
** detect_end
** File description:
** detect_end
*/

#include <unistd.h>
#include "../include/my.h"

static void stop_simulation(void)
{
    write(1, "STOP_SIMULATION\n", strlen("STOP_SIMULATION\n"));
}

int detect_end(char *str)
{
    if (strcmp(str, "Track Cleared") == 0) {
        stop_simulation();
        return 1;
    }
    return (0);
}
