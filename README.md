# holbertonschool-simple_shell

Simple shell project for Holberton School.

## Table of contents
- [What is the shell?](#what-is-the-shell)
- [About this project](#about-this-project)
- [Essential Functionalities of the Simple Shell](#essential-functionalities-of-the-simple-shell)
- [File description](#file-description)
- [List of allowed functions and system calls for this project](#list-of-allowed-functions-and-system-calls-for-this-project)
- [USAGE](#usage)

## What is the shell?

A shell is a program that provides a user interface to an operating system (OS). It allows you to interact with the computer by typing commands and executing them.

## About this project

This project is a simple version of the Linux shell made for Holberton School as part of the "Low-level programming & Algorithm - Linux and Unix system programming" curriculum. It is created using the C programming language and implements several functionalities of a real shell.

## Essential Functionalities of the Simple Shell:

- Displays a prompt `#cisfun$ ` and waits for user input.
- Runs all commands of type "executable program" (e.g., `ls` and `/bin/ls`).
- Implements the following built-in commands:
  - `exit`
  - `env`
  - `setenv`
  - `unsetenv`
- Handles commands with arguments.
- Manages the `PATH` global variable.
- Handles the EOF (End of File) condition.
- Handles the `Ctrl + C` signal without exiting the shell.

## File description

- **man_1_simple_shell**: Manual page for the simple shell.
- **shell.h**: Header file containing function prototypes and necessary declarations.
- **shell.c**: Contains the main function.
- **sig_handler.c**: Handles the `Ctrl + C` signal.
- **_EOF.c**: Handles the End Of File (EOF) condition.
- **string.c**: Utility functions for string manipulation:
  - `_putchar`: Prints a character.
  - `_puts`: Prints a string.
  - `_strlen`: Returns the length of a string.
  - `_strdup`: Copies a string to newly allocated memory.
  - `concat_all`: Concatenates three strings into newly allocated memory.
- **line_exec.c**: Functions for executing commands:
  - `splitstring`: Splits a string into an array of words.
  - `execute`: Executes a command using `execve`.
  - `realloc`: Reallocates memory block.
  - `freearv`: Frees a 2D array.
- **linkpath.c**: Functions for handling the `PATH` environment variable:
  - `_getenv`: Returns the value of a global variable.
  - `add_node_end`: Adds a node to a singly linked list.
  - `linkpath`: Creates a singly linked list for `PATH` directories.
  - `_which`: Finds the pathname of a command.
  - `free_list`: Frees the linked list of `PATH` directories.
- **checkbuild.c**: Functions to check built-in commands:
  - `checkbuild`: Checks if a command is a built-in command.
- **buildin.c**: Handles built-in commands:
  - `exitt`: Handles the `exit` built-in command.
  - `_atoi`: Converts a string to an integer.
  - `env`: Prints the current environment variables.
  - `_setenv`: Initializes or modifies a global variable.
  - `_unsetenv`: Removes a global variable.

## List of allowed functions and system calls for this project

- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `stat (__xstat)` (man 2 stat)
- `lstat (__lxstat)` (man 2 lstat)
- `fstat (__fxstat)` (man 2 fstat)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)

## USAGE

You can try our shell by following these steps:

### Step 1: Clone our repository
Clone the repository using the following command (make sure you have `git` installed on your machine first):

```bash
git clone https://github.com/NGB242/holbertonschool-simple_shell.git
```

### Step 2: Change directory to simple_shell

Navigate to the directory of the project you have just cloned using the following command:

```bash
cd simple_shell
```

### Step 3: Compile the C files

Compile les fichiers C pour générer l'exécutable `hsh` avec la commande suivante :

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

This command uses the following options:
- `-Wall`: enables all compiler warnings.
- `-Werror`: treats all warnings as errors, preventing compilation if warnings are present in the code.
- `-Wextra`: enables additional warnings not included with `-Wall`.
- `-pedantic`: makes the compiler more strict about compliance with C language standards, by flagging up practices that do not conform to C standards.
- `*.c`: specifies all `.c` source files present in the directory to be compiled.
- `-o hsh`: specifies that the resulting executable file will be named `hsh` (you can choose another name if you wish).

Once this command has been executed, an `hsh` executable file will be generated in the current directory. If compilation fails, the terminal will display error messages detailing what went wrong. Check that all necessary `.c` source files are present and that the source code contains no syntax errors.


### Step 4: Run the shell

Once compiled, you can run the shell with the following command :

```bash
./hsh
```

This will launch the shell and display the `#cisfun$` command prompt, allowing you to enter commands. You can try out the following commands for yourself:

- **`ls`** : Displays a list of files and directories in the current directory.
- **`exit`**: Exits the shell.
- **`env`** : Displays current environment variables.
- **`setenv` [variable] [value]**: Sets a new environment variable or modifies an existing one.
- unsetenv` [variable]**: Deletes an environment variable.
- Customized commands**: You can also execute other programs or commands located in directories accessible via the PATH.

The shell will wait for your input at each `#cisfun$` prompt. When you type a command, the shell will interpret and execute it. If the command is an executable program, it will be launched. If it's a built-in command (like `exit` or `env`), the shell will execute the corresponding functionality directly.

### Exiting the shell

When you want to quit the shell, there are several options:

1. **Type `exit` and press `Enter`** :
    ``bash
    exit
    ```
    This will close the shell cleanly.

2. **Press `Ctrl + D`** to send an EOF (End Of File) signal, which tells the shell to close.

3. **Use `Ctrl + C`**: this interrupts the current command (if one is running) without closing the shell. This feature is handled by signal processing, allowing the shell to continue running without closing immediately.

This allows you to test different ways of interacting with the shell and exit cleanly when you're finished.

This section explains how to interact with the shell once it has been launched, offering examples of commands and detailing the various ways of exiting the shell.

## Shell like interactive mode:
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

## Shell like non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

## Compilation

Your shell will be compiled this way: *gcc -Wall -Werror -Wextra -pedantic -std=gnu89 .c -o hsh


