/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"

static void free_all(mysh_t *sh)
{
    int i = 0;
    while (i < sh->first) {
        free(sh->args[i]);
        i++;
    }
    free(sh->args);
    while (i < sh->b) {
        free(sh->str[i]);
        i++;
    }
    free(sh->str);
    while (sh->env[i] != NULL) {
        free(sh->env[i]);
        i++;
    }
    free(sh->env);
    free(sh);
}

void my_exit(mysh_t *sh)
{
    if (sh->first > 2) {
        write_error("exit: Expression Syntax.\n");
        return;
    }

    int value = sh->first == 1 ? 0 : my_atoi(sh->args[1]);
    free_all(sh);
    exit(value);
}

char *my_strdup(const char *const str)
{
    if (str == NULL)
        return NULL;
    size_t len = my_strlenn(str);
    char *duplicate = malloc((len + 1) * sizeof(char));
    if (duplicate == NULL)
        return NULL;
    my_strcpy(duplicate, str);
    return duplicate;
}

int split_commands(char* command, char* commands[], char delimiter)
{
    int num_commands = 0;
    char delimiter_str[2];
    delimiter_str[0] = delimiter;
    delimiter_str[1] = '\0';

    char* token = strtok(command, delimiter_str);
    while (token != NULL) {
        commands[num_commands++] = token;
        token = strtok(NULL, delimiter_str);
    }
    return num_commands;
}
