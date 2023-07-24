/*
** EPITECH PROJECT, 2022
** my_word_array.c
** File description:
** test
*/

#include "lemin.h"
#include "my.h"

static int is_alphnum(char c)
{
    if ((c >= 'a' && c <= 'z')
    || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '-')
        return 1;
    else
        return 0;
}

static int is_letter(char c, int size)
{
    int alp = is_alphnum(c);

    if (alp == 1 && size == -1)
        return 1;
    else if (size == -1)
        return 0;
    if (alp == 1)
        size++;
    return size;
}

static int is_word1(char c, char d, int cw)
{
    int alpd = is_alphnum(d);
    int alpc = is_alphnum(c);

    if (cw == -1 && alpd == 1 && alpc == 0)
        return 1;
    else if (cw == -1)
        return 0;
    if (alpd == 1 && alpc == 0)
        cw++;
    return cw;
}

static void write_words(char **tab, char const *str, int count_words)
{
    int j = 0; int k = 1; int i = 0;
    if (is_letter(str[0], -1) == 1) {
        tab[0][0] = str[0];
        j = 1;
        if (is_letter(str[1], -1) == 0) {
            tab[0][1] = '\0';
            i++;
            k = 2;
            j = 0;
        } }
    for (i = i; i < count_words; i++) {
        for (k = k; is_letter(str[k], -1) == 0; k++);
        while (is_word1(str[k], str[k - 1], -1) == 0) {
            tab[i][j] = str[k];
            k++;
            j++;
        }
        tab[i][j] = '\0';
        j = 0; k++;
    }
}

char **my_word_array_bis(char const *str)
{
    int size = 0;
    int j = 0;
    int	k = 0;
    int count_words = 0;

    for (int i = 0 ; i <= my_strlen(str) ; i++) {
        if (i > 0)
            count_words = is_word1(str[i], str[i - 1], count_words);
    }
    char **tab = malloc(sizeof(char *) * (count_words + 1));
    for (k = k; j < count_words ; k++) {
        size = is_letter(str[k], size);
        if (k > 0 && is_word1(str[k], str[k - 1], -1) == 1) {
            tab[j] = malloc(sizeof(char) * (size + 1));
            size = 0;
            j++;
        } }
    tab[j] = NULL;
    write_words(tab, str, count_words);
    return tab;
}
