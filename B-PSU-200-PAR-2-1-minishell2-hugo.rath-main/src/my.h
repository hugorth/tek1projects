/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <dirent.h>
    #include <stdbool.h>
    #include <linux/limits.h>
    #include <pwd.h>
    #define BUFFER_SIZE 256

    typedef struct mysh {
        char **env;
        char *buff;
        char **str;
        char **args;
        char *oldpwd;
        int first;
        int mode;
        int b;
        int exit;
    } mysh_t;

    size_t my_strlenn(const char *const str);
    void split7 (char *args[64], char *command_name,
    char command_path[BUFFER_SIZE], char **envp);
    int split_commands(char* command, char* commands[], char delimiter);
    char *my_strdup(const char *const str);
    char* trim_spaces(char* str);
    void print_prompt(void);
    char* read_command(void);
    int should_exit(const char* command);
    void split_pipe_commands(const char* command, char** pipe_commands);
    void split6(char *args[64]);
    char* my_strncpy(char* dest, const char* src, size_t n);
    void copy_env(mysh_t *sh, char **envp);
    void minishell(mysh_t *sh);
    char *check_str(char *buff);
    void get_the_buffers(mysh_t *sh);
    int split(mysh_t *sh, int i, int temp);
    void split1(mysh_t *sh, int nbr);
    void get_args(mysh_t *sh, char *buff);
    char *cleanstr(char *buff);
    void check_line(mysh_t *sh);
    int count_args(char *buff, char sep);
    char *my_strcpy(char *dest, char const *src);
    void check_command(mysh_t *sh);
    void my_exit(mysh_t *sh);
    void get_env(mysh_t *sh);
    void my_setenv(mysh_t *sh);
    void my_unsetenv(mysh_t *sh);
    int my_cd(mysh_t *sh);
    int exec_bin(mysh_t *sh);
    char **get_path(char **env, char const *var);
    int exec_prog(mysh_t *sh);
    void my_putchar(char c);
    void my_putstr(char const *str);
    int my_strlen(char *const str);
    int my_strcmp(char *const str1, char *const str2);
    char *my_strcat(char *dest, char const *src);
    int write_error(char const *str);
    int my_atoi(char *str);
    int my_strncmp(char const *s1, char const *s2, int n);
    int isnt_dir(struct stat st, char *name);
    bool check_args(char **args);
    bool check_first_char(char c);
    bool check_alphanumeric(char *str);
    void display_error_msg(void);
    bool is_valid_char(char *str);
    bool is_alpha(char c);
    int custom_strlen(char *str);
    int my_strcmp1(const char *str1, const char *str2);
    static const int ERROR = 84;
    static const int SUCCESS = 0;
    static const int TRUE = 1;
    static const int FALSE = 0;

#endif /* MY_H */
