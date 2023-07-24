/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** word array
*/

#include <stdio.h>
#include <stdlib.h>

int char_is_alphanum(char c);

int nb_word(char const *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (char_is_alphanum(str[i]) == 1
        && char_is_alphanum(str[i + 1]) == 0) {
            size++;
    }
    return size;
}

char **size_word(char const *str, char **stock, int word)
{
    int size = 0;
    int pos = 0;

    stock = malloc(sizeof(char *) * (word + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        size = size + char_is_alphanum(str[i]);
        if (char_is_alphanum(str[i]) == 1
        && char_is_alphanum(str[i + 1]) == 0) {
            stock[pos] = malloc(sizeof(char) * (size + 2));
            pos++;
            size = 0;
        }
    }
    return stock;
}

int start_str(char const *str)
{
    int c = 0;

    while (!((str[c] >= 'a' && str[c] <= 'z') || (str[c] >= 'A'
    && str[c] <= 'Z') || (str[c] >= '0' && str[c] <= '9'))) {
        c++;
    }
    return c;
}

char **my_str_to_word_array(char const *str)
{
    char **stock = 0;
    int x = 0;
    int y = 0;
    int word = nb_word(str);
    int start = start_str(str);
    stock = size_word(str, stock, word);
    for (int i = start; str[i] != '\0'; i++) {
        if (char_is_alphanum(str[i]) == 0
        && char_is_alphanum(str[i + 1]) == 1) {
            stock[x][y] = '\0';
            y = 0;
            x++;
            continue;
        } if (char_is_alphanum(str[i]) == 1)
            stock[x][y] = str[i];
        y++;
    }
    stock[x][y - 1] = '\0';
    stock[x + 1] = 0;
    return stock;
}
