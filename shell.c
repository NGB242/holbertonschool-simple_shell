#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - A simple UNIX command line interpreter.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *args[2];
    pid_t pid;

    while (1)
    {
        
        printf("#cisfun$ ");
        fflush(stdout);

        
        nread = getline(&line, &len, stdin);
        if (nread == -1) 
        {
            if (feof(stdin))
                printf("\n");
            break;
        }

        
        line[nread - 1] = '\0';

        
        args[0] = line;
        args[1] = NULL;

        
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            continue;
        }
        if (pid == 0) 
        {
            if (execve(args[0], args, environ) == -1)
            {
                perror(line);
                exit(EXIT_FAILURE);
            }
        }
        else 
        {
            wait(NULL);
        }
    }

    free(line);
    return (0);
}
