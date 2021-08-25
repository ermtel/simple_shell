#include "holberton.h"


/**
 * shell_exit - frees @args and @buffer and exits the shell.
 * @buffer: a line of command entered by user using getline.
 * @args: the array of commands entered by user.
 * @environ: the environmental variables.
 * Return: Void.
 */

void shell_exit(char *buffer, char **args, char **environ)
{
	(void)environ;
	free(buffer);
	free_dbl_ptr(args);
	exit(EXIT_SUCCESS);
}

/**
 * print_env - prints the environmental variables.
 * @buffer: a line entered by the user using getline.
 * @args: the array of commands entered by the user.
 * @environ: the environmental variables.
 * Return: 0 on success.
 */

void print_env(char *buffer, char **args, char **environ)
{
	unsigned int i;

	free(buffer);
	free_dbl_ptr(args);
	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	exit(EXIT_SUCCESS);
}
