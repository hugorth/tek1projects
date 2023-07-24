/*
** EPITECH PROJECT, 2022
** strtowdtab
** File description:
** oui
*/

#include "my.h"

int word_count(char const *str, char *sep)
{
    int nb = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == sep[0])
            nb++;
    }
    return (nb + 1);
}

char **my_str_to_wordtab(char *str, char *sep)
{
    int len = strlen(str);
    char **tab = malloc(sizeof(char *) * (len + 1));
    int status = 0;
    int i = 0;
    while (i < len) {
        char *word = extract_word(str, sep, i, &i);
        if (word != NULL) {
            tab[status] = word;
            status++;
        }
    }
    tab[status] = NULL;
    return tab;
}
