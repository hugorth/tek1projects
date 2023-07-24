/*
** EPITECH PROJECT, 2022
** my_find_prime_sup.c
** File description:
** find prime sup
*/

int verif_prime_sup(int nb, int i)
{
    if (i == nb)
        i++;
    else {
        if (nb % i < 1)
            return 1;
    }
    return 0;
}

int is_prime_number_sup(int nb)
{
    int res = 0;

    for (int i = 2; i < 10; i++) {
        res = verif_prime_sup(nb, i);
        if (res == 1)
            return 0;
    }
    return 1;
}

int my_find_prime_sup(int nb)
{
    while (is_prime_number_sup(nb) != 1) {
        if (nb > 2147483647)
            return 0;
        nb++;
    }
    return nb;
}
