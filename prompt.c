#include "holberton.h"
#include <stdio.h>


/**
 * _readline - reads input commands and parameters from user.
 * Return: the line entered by the user.
 */

char *_readline(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t num_char;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	num_char = getline(&buffer, &bufsize, stdin);
	if (num_char == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buffer);

		exit(EXIT_SUCCESS);
	}

	return (buffer);
}
