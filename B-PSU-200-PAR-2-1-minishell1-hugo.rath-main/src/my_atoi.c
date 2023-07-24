/*
** EPITECH PROJECT, 2023
** atoi
** File description:
** atoi
*/

int my_atoi(char *str)
{
    int val;
    val = 0;
    for (; *str; str++) {
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        } else
            return (val);
    }
    return (val);
}
