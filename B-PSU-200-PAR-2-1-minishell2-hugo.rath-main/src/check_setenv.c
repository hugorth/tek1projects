/*
** EPITECH PROJECT, 2023
** check
** File description:
** check
*/

#include "my.h"

int custom_strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

bool is_alpha(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z') || c == '_';
}

bool is_valid_char(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_alpha(str[i])) {
            return false;
        }
    }
    return true;
}

void display_error_msg(void)
{
    write_error("setenv: Variable name must\n");
    write_error("contain alphanumeric characters.\n");
}

bool check_alphanumeric(char *str)
{
    int length = custom_strlen(str);

    if (is_valid_char(str) && length != 0) {
        return false;
    }
    display_error_msg();
    return true;
}
