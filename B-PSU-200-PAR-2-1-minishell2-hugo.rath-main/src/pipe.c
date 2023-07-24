/*
** EPITECH PROJECT, 2023
** pipe
** File description:
** pipe
*/

#include "my.h"

char* trim_spaces(char* str)
{
    int len = my_strlen(str);
    int start = 0;
    int end = len - 1;

    while (start < len && (str[start] == ' ' || str[start] == '\t')) {
        start++;
    }

    while (end >= start && (str[end] == ' ' || str[end] == '\t')) {
        end--;
    }
    char* trimmed_str = malloc((end - start + 2) * sizeof(char));
    my_strncpy(trimmed_str, str + start, end - start + 1);
    trimmed_str[end - start + 1] = '\0';

    return trimmed_str;
}

void print_prompt(void)
{
    if (isatty(STDOUT_FILENO))
        my_putstr("$> ");
}

char* read_command(void)
{
    char* command = NULL;
    size_t command_size = 0;

    ssize_t line_length = getline(&command, &command_size, stdin);
    if (line_length == -1) {
        free(command);
        return NULL;
    }
    if (command[line_length - 1] == '\n')
        command[line_length - 1] = '\0';
    return command;
}

void split_pipe_commands(const char* command, char** pipe_commands)
{
    char* command_copy = my_strdup(command);
    char* token;
    char* saveptr;
    int i = 0;

    token = strtok_r(command_copy, "|", &saveptr);
    while (token != NULL) {
        char* trimmed_command = trim_spaces(token);
        if (my_strlen(trimmed_command) > 0) {
            pipe_commands[i] = trimmed_command;
            i++;
        }
        token = strtok_r(NULL, "|", &saveptr);
    }
    pipe_commands[i] = NULL;

    free(command_copy);
}

void split7 (char *args[64], char *command_name,
char command_path[BUFFER_SIZE], char **envp)
{
    if (my_strcmp1(args[0], "setenv") == 0 ||
    my_strcmp1(args[0], "unsetenv") == 0) {
        execve(command_path, args, envp);
        exit(1);
    } else {
        if (execve(command_path, args, envp) == -1) {
            my_putstr(command_name);
            my_putstr(": Command not found.\n"); exit(1);
        }
    }
}
