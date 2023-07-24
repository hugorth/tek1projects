/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** swap
*/

void my_swap(int *a, int *b)
{
    int tmp = 0;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
