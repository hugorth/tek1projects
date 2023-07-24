/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** compute square root
*/

int my_compute_square_root(int nb)
{
    int i = 1;
    int res = 0;
    int stock = 0;

    while (res < nb) {
        stock = i * 2 - 1;
        res = res + stock;
        i++;
    }
    i--;
    if (i * i != nb)
        return 0;
    return i;
}
