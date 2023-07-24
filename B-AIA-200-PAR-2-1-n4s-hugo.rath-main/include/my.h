/*
** EPITECH PROJECT, 2023
** myh
** File description:
** myh
*/

#ifndef myh
    #define myh

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>

    typedef struct n4s_t {
        double left;
        double right;
        double mid;
        double speed;
    } n4s;

int launch_ia(n4s *info, char **tab);
void control_speed(n4s *info);
void set_speed(double value);
void set_direction(double value, int neg);
int detect_end(char *str);
char **my_str_to_wordtab(char *str, char *sep);
char *adding(char *line, int deal, char *buf, int *begin);
char *extract_word(char *str, char *sep, int start_index, int *end_index);

#endif /* !myh */
