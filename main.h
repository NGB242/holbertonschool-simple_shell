#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "main.h"

/* Function Prototypes */
int main(void);
char **_splitline(char *line);
int _execute(char **args);
char *_find_path_command(char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
pid_t _fork(void);
int _execve(const char *pathname, char *const argv[], char *const envp[]);
void _perror(const char *s);
void free_line(char *line);
void display_prompt(void);


/* Déclaration de l'environnement */
extern char(**environ);

#endif /* MAIN_H */
