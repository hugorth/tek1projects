/*
** EPITECH PROJECT, 2022
** alphanum
** File description:
** fzg
*/

int char_is_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z')
    || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}
