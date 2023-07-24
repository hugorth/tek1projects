/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** get nbr
*/

int my_getnbr(char const *str)
{
    int res = 1;
    int pos = 0;
    int nbr = 0;

    while (str[pos] == '+' || str[pos] == '-') {
        if (str[pos] == '-')
            res = res * -1;
        pos++;
    } while (str[pos] >= '0' && str[pos] <= '9') {
        nbr = nbr * 10 + str[pos] - '0';
        pos++;
    }
    return (nbr * res);
}
