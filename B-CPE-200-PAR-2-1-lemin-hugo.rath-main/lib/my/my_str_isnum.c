/*
** EPITECH PROJECT, 2022
** my_str_isnum.c
** File description:
** str isnum
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
    }
    return 0;
}
