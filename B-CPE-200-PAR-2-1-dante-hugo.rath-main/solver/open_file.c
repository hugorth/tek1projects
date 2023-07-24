/*
** EPITECH PROJECT, 2023
** open_file.c
** File description:
** open the file
*/

#include "dante.h"
#include "struct.h"

int len_file(char const *filepath)
{
    struct stat tmp;
    stat(filepath, &tmp);
    return tmp.st_size;
}

char *open_file(char const *filepath)
{
    int file = 0;
    int size = len_file(filepath);
    int status = 84;
    file = open(filepath, O_RDONLY);
    if (chek_files(file) == 84) {
        exit(status);
    }
    if (size == 0) {
        return NULL;
    }
    char *buffer = malloc(sizeof(char) * (size + 1));
    buffer[size] = '\n';
    read(file, buffer, size);
    close(file);
    return buffer;
}
