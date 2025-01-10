#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define END_OF_FILE -2
#define EXIT -3


/* Global environemnt */
extern char **environ;
/* Global program name */
char *name;
/* Global history counter */
int hist;


/* Prototypes */
int main(void);
pid_t _fork(void);
int _execve(const char *pathname, char *const argv[], char *const env[]);
void _perror(const char *s);
void free_line(char *line);
void display_prompt(void);
extern char (**environ);
int main(void);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_location(char *command);
int execute(char **args, char **front);


/* Argument Helpers */
void handle_line(char **line, ssize_t read);
void variable_replacement(char **args, int *exe_ret);
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);
void free_args(char **args, char **front);
char **replace_aliases(char **args);

/* String functions */
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_itoa(int num);
int num_len(int num);

/* Builtins */
int (*get_builtin(char *command))(char **args, char **front);
int sh_exit(char **args, char **front);
int sh_env(char **args, char __attribute__((__unused__)) **front);
int sh_setenv(char **args, char __attribute__((__unused__)) **front);
int sh_unsetenv(char **args, char __attribute__((__unused__)) **front);
int sh_cd(char **args, char __attribute__((__unused__)) **front);
int sh_alias(char **args, char __attribute__((__unused__)) **front);
int sh_help(char **args, char __attribute__((__unused__)) **front);

/* env_handlers */
char **_copyenv(void);
char **_getenv(const char *var);
char *get_env_value(char *beginning, int len);

/* Error Handling */
int create_error(char **args, int err);
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);

/* mem_formaters and linked_lists */
void free_env(void);
void free_alias_list(alias_t *head);

/* help */
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);

/* file proccessor */
int proc_file_commands(char *file_path, int *exe_ret);

#endif /* SHELL_H */
