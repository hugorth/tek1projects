/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** str capitalize
*/

char *my_strlowcase2(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return str;
}

char *my_strcapitalize(char *str)
{
    int cmp = 0;

    str = my_strlowcase2(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            cmp++;
        } else {
            cmp = 0;
        } if (str[i - 1] >= '0' && str[i - 1] <= '9')
            cmp = 2;
        if (cmp == 1) {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
