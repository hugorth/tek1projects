/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** revstr
*/

int my_strlen3(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_revstr(char *str)
{
    int size = my_strlen3(str);
    char stock = 0;

    for (int i = 0; i < size; i++) {
        stock = str[i];
    str[i] = str[size - 1];
    str[size - 1] = stock;
    size--;
    }
    return str;
}
