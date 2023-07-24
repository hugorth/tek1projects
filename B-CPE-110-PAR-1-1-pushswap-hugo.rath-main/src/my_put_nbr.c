/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** put nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int stock = 0;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    } if (nb >= 0 && nb <= 9) {
        my_putchar(nb + '0');
    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        stock = (nb % 10);
        my_putchar(stock + '0');
    }
    return 0;
}
