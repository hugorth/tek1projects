/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** strlen
*/

int my_strlen(char const *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++)
        size++;
    return size;
}
