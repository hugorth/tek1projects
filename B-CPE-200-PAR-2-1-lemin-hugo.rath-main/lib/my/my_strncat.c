/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** str n cat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int	size = my_strlen(dest);
    int	i = 0;

    while (src[i] != '\0' && i < nb) {
        dest[size + i] = src[i];
        i++;
    }
    dest[size + i] = '\0';
    return dest;
}
