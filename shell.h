#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <sys/types.h>

/* Prototypes */
int main(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
pid_t _fork(void);
int _execve(const char *pathname, char *const argv[], char *const env[]);
void _perror(const char *s);
void free_line(char *line);
void display_prompt(void);
extern char (**environ);

#endif /* SHELL_H */
