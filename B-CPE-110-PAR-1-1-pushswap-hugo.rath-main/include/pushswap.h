/*
** EPITECH PROJECT, 2022
** list.c
** File description:
** list
*/

#ifndef PUSHSWAP_H
    #define PUSHSWAP_H
    #include <stdlib.h>
    #include <stdio.h>

typedef struct list_t {
    int *list_a;
    int *list_b;
    int size_a;
    int size_b;
    int *next;
    int value;
} list_s;

int *list_a(int ac, char **av);
int *list_b(int ac);
int my_getnbr(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
list_s sa_do(list_s *list);
list_s sb_do(list_s *list);
list_s sa_do1(list_s *list);
list_s pa_do(list_s *list);
list_s pb_do(list_s *list);
list_s rra_do(list_s *list);
list_s rrb_do(list_s *list);
list_s ra_do(list_s *list);
list_s rb_do(list_s *list);
list_s init_pushswap(list_s *list, int ac, char **av);
list_s pushswap(list_s *list);
list_s pa1_do(list_s *list);
int my_put_nbr(int nb);

#endif /* PUSHSWAP_H */
