/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** is prime
*/

int verif_prime(int nb, int i)
{
    if (i == nb)
        i++;
    else {
        if (nb % i < 1)
            return 1;
    }
    return 0;
}

int my_is_prime(int nb)
{
    int res = 0;

    for (int i = 2; i < 10; i++) {
        res = verif_prime(nb, i);
        if (res == 1)
            return 0;
    }
    return 1;
}
