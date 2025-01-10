#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
        /* Display the prompt */
        printf("#cisfun$ ");
        fflush(stdout);

        /* Read the command line */
        nread = getline(&line, &len, stdin);
        if (nread == -1) /* Handle EOF or error */
        {
            if (feof(stdin))
                printf("\n");
            break;
        }

        /* Remove the newline character */
        line[nread - 1] = '\0';

        /* Set up arguments for execve */
        args[0] = line;
        args[1] = NULL;

        /* Create a child process */
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            continue;
        }
        if (pid == 0) /* Child process */
        {
            if (execve(args[0], args, environ) == -1)
            {
                perror(line);
                exit(EXIT_FAILURE);
            }
        }
        else /* Parent process */
        {
            wait(NULL);
        }
    }

    free(line);
    return (0);
}
