/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** str cat
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int size = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[size + i] = src[i];
        i++;
    }
    dest[size + i] = '\0';
    return dest;
}
