/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** compute power rec
*/

int my_compute_power_rec(int nb, int p)
{
    int res = 0;

    if (p < 0) {
        return 0;
    } else if (p == 0) {
        return 1;
    } else {
        res = nb * my_compute_power_rec(nb, p - 1);
        if (res > 2147483647)
            return 0;
        return res;
    }
}
