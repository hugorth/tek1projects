/*
** EPITECH PROJECT, 2023
** oui
** File description:
** oui
*/

#include "my.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int find_non_whitespace(char *input, int a)
{
    int pos = a;

    for (; input[a] != '\0'; a++) {
        if (input[a] != ' ' && input[a] != '\t') {
            pos = a;
            break;
        }
    }
    return pos;
}

static char *remove_extra_spaces(char *buffer)
{
    int len = my_strlen(buffer);
    char *result = malloc(sizeof(char) * (len + 1));
    int i, j;

    for (i = find_non_whitespace(buffer, 0), j = 0; buffer[i] != '\0'; i++) {
        if ((buffer[i] == ' ' || buffer[i] == '\t') &&
        (buffer[i + 1] == ' ' || buffer[i + 1] == '\t')) {
            result[j++] = ' ';
            i = find_non_whitespace(buffer, i) - 1;
        } else {
            result[j++] = buffer[i];
        }
    }
    result[j] = '\0';
    return result;
}

char *cleanstr(char *input_str)
{
    int i;

    input_str = remove_extra_spaces(input_str);
    for (i = 0; input_str[i] != '\0'; i++) {
        if (input_str[i] == '\n') {
            input_str[i] = '\0';
            break;
        }
    }
    while (input_str[i - 1] == ' ' || input_str[i - 1] == '\t') {
        input_str[--i] = '\0';
    }
    return input_str;
}
