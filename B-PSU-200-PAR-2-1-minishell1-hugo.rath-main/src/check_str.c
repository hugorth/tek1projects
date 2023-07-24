/*
** EPITECH PROJECT, 2023
** checkfile
** File description:
** check
*/

#include "my.h"

char *check_str(char *buff)
{
    int status = 0;
    int i = 0;

    while (buff[i] != '\n') {
        if (buff[i] == ' ' || buff[i] == '\t')
            status++;
        i++;
    }
    if (status == (my_strlen(buff) - 1))
        return NULL;
    return buff;
}
