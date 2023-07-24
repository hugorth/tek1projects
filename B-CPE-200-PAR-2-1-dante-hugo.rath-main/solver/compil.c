/*
** EPITECH PROJECT, 2023
** compil.c
** File description:
** all functions basics
*/

#include "dante.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

int my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        (nb = nb * -1);
    }
    if (nb / 10 != 0) {
        my_putnbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return nb;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i]; i++) {
        if ((s1[i] != s2[i])) {
            return 0;
        }
    }
    return 0;
}
