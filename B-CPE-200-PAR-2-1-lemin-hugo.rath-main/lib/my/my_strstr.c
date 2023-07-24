/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** strstr
*/

int check_next(char *str, char const *to_find, int i)
{
    int j = 0;

    while (to_find[j] != '\0' && str[i + j] != '\0') {
        if (str[i + j] != to_find[j])
            return 1;
        j++;
    }
    return 0;
}

int cmp_first(char *str, char const *to_find, int i)
{
    if (str[i] == to_find[0]) {
        if (check_next(str, to_find, i) == 0)
            return 1;
    }
    return 0;
}

char *my_strstr(char *str , char const *to_find)
{
    if (to_find[0] == '\0')
        return str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (cmp_first(str, to_find, i) == 1)
            return (&str[i]);
    }
    return "";
}
