/*
** EPITECH PROJECT, 2023
** extract_word.c
** File description:
** extract word
*/

#include "my.h"

int skip_separators(char *str, char *sep, int start_index)
{
    int i = start_index;
    while (str[i] != '\0' && str[i] == sep[0]) {
        i++;
    }
    return i;
}

int find_next_word(char *str, char *sep, int start_index)
{
    int j = start_index;
    while (str[j] != '\0' && str[j] != sep[0]) {
        j++;
    }
    return j;
}

char *extract_word(char *str, char *sep, int start_index, int *end_index)
{
    int i = skip_separators(str, sep, start_index);
    if (str[i] == '\0') {
        *end_index = i;
        return NULL;
    }
    int j = find_next_word(str, sep, i);
    *end_index = j;
    char *word = malloc(sizeof(char) * (j - i + 1));
    if (word == NULL) {
        return NULL;
    }
    int k = 0;
    for (; i < j; i++, k++) {
        word[k] = str[i];
    }
    word[k] = '\0';
    return word;
}
