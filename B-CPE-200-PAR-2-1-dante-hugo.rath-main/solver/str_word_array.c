/*
** EPITECH PROJECT, 2023
** test.c
** File description:
** str word array
*/

#include "dante.h"
#include "struct.h"

int alphanumeric(char c)
{
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9') ||
        (c == '*')) {
        return (1);
    }
    return (0);
}

int words_str(char const *str)
{
    int words = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == '\0') {
            words++;
        }
        if ((alphanumeric(str[i]) == 1) && (alphanumeric(str[i + 1]) == 0)) {
            words++;
        }
    }
    return words;
}

int *count_len_word(char const *str)
{
    int *len_word = malloc(sizeof(int) * (words_str(str) + 1));
    int i = 0;
    int park_len = 0;
    int size_1word = 0;
    while (str[i] != '\0') {
        while (alphanumeric(str[i]) == 0 && str[i] != '\0') {
            i++;
        }
        while (alphanumeric(str[i]) == 1 && str[i] != '\0') {
            size_1word++;
            i++;
        }
        len_word[park_len] = size_1word;
        park_len++;
        size_1word = 0;
    }
    return len_word;
}

char **array_double(char *str)
{
    char **db_array = malloc(sizeof(char *) * (words_str(str) + 1));
    int *lens_words = count_len_word(str);
    int row = 0; int col = 0;
    int i = 0;
    while (str[i] != '\0') {
        db_array[row] = malloc(sizeof(char ) * (lens_words[row] + 1));
        while (alphanumeric(str[i]) == 0 && str[i] != '\0') {
            i++;
        }
        while (alphanumeric(str[i]) == 1 && str[i] != '\0') {
            db_array[row][col] = str[i];
            i++;
            col++;
        }
        db_array[row][col] = '\0';
        row += 1;
        col = 0;
    }
    db_array[row] = NULL;
    return db_array;
}
