/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** str n cpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; i < n; i++) {
        if (src[i] == '\0') {
            dest[i] = '\0';
            return dest;
        }
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
