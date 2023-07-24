/*
** EPITECH PROJECT, 2023
** pipe_bis
** File description:
** pipe_bis
*/

#include "my.h"

void errorpath(char **paths)
{
    if (paths == NULL) {
        my_putstr("erreur: PATH variable not found");
        exit(1);
    }
}

void split6(char *args[64])
{
    char* command_name = args[0];
    extern char **environ; char **envp = environ;
    char** paths = get_path(envp, "PATH"); char command_path[BUFFER_SIZE];
    errorpath(paths);
    for (int i = 0; paths[i] != NULL; i++) {
        size_t path_length = my_strlen(paths[i]);
        size_t command_name_length = my_strlen(command_name);
        if (path_length + command_name_length >= BUFFER_SIZE) {
            my_putstr("erreur: too long command");
            exit(1);
        }
        my_strcpy(command_path, paths[i]);
        if (command_path[path_length - 1] != '/') {
            command_path[path_length] = '/';
            path_length++;
        } for (size_t idx = 0; idx < command_name_length; ++idx)
            command_path[path_length + idx] = command_name[idx];
        command_path[path_length + command_name_length] = '\0';
        execve(command_path, args, envp);
    } split7(args, command_name, command_path, envp); exit(1);
}
