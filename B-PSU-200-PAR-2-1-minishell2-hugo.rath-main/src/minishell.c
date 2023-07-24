/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"

void execute_commande(const char* command)
{
    char* args[64];
    char* arg;
    char* saveptr2;
    int k = 0;

    arg = strtok_r((char*)command, " \t", &saveptr2);
    while (arg != NULL) {
        args[k] = arg;
        arg = strtok_r(NULL, " \t", &saveptr2);
        k++;
    }
    args[k] = NULL;
    split6(args);
}

void split5(int j, int prev_read, char **pipe_commands, int pipefd[2])
{
    if (j != 0) {
        dup2(prev_read, 0);
        close(prev_read);
    }
    if (pipe_commands[j + 1] != NULL) {
        dup2(pipefd[1], 1);
        close(pipefd[1]);
    }
    close(pipefd[0]);

    execute_commande(pipe_commands[j]);

    exit(1);
}

void split10(int prev_read)
{
    if (prev_read != 0) {
        close(prev_read);
    }
}

void execute_pipe_commands(char** pipe_commands)
{
    int prev_read = 0;
    for (int j = 0; pipe_commands[j] != NULL; j++) {
        int pipefd[2];
        if (pipe(pipefd) == -1) {
            perror("Erreur lors de la création du pipe");
            exit(1);
        }
        pid_t pid = fork();
        if (pid < 0) {
            perror("Erreur lors de la création du processus fils");
            exit(1);
        } if (pid == 0) {
            split5(j, prev_read, pipe_commands, pipefd);
        } else {
            close(pipefd[1]);
            split10(prev_read);
            prev_read = pipefd[0];
            waitpid(pid, NULL, 0);
        }
    }
}

void minishell(mysh_t *sh)
{
    char* command;
    while (1) {
        print_prompt();
        command = read_command();
        if (command == NULL) {
            return;
        } if (should_exit(command)) {
            free(command);
            return;
        }
        char* commands[64];
        int num_commands = split_commands(command, commands, ';');
        for (int i = 0; i < num_commands; i++) {
            char* pipe_commands[64];
            split_pipe_commands(commands[i], pipe_commands);
            execute_pipe_commands(pipe_commands);
            sh->buff = commands[i];
            check_line(sh);
        } free(command);
    }
}
