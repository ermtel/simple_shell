#include "holberton.h"

/**
 * error_mess - writes an error message when command is not found.
 * @argv: the name of the shell.
 * @comm: the commands entered by the user.
 * @count: the number of times commands have been executed.
 *
 * Return: Void.
 */
void error_mess(char **argv, char **comm, int count)
{
	int mul, numlength, copy;

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);

	copy = count;
	mul = 1;
	numlength = 1;
	while (copy >= 10)
	{
		copy /= 10;
		mul *= 10;
		++numlength;
	}
	while (numlength > 1)
	{
		if ((count / mul) < 10)
			_puterror((count / mul) + '0');
		else
			_puterror((count / mul) % 10 + '0');
		--numlength;
		mul /= 10;
	}
	_puterror(count % 10 + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, comm[0], _strlen(comm[0]));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * _puterror - puts a char to the STD
 * @c: character to write out
 *
 * Return: int to print
 */
int _puterror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * comm_null - free the buffer when command is null.
 * @buffer: the buffer created from getline.
 */

void comm_null(char *buffer)
{
	free(buffer);
	exit(EXIT_SUCCESS);
}
/**
 * fork_fail - handles a fork fail
 *
 * Return: void
 */
void fork_fail(void)
{
	perror("Error:");
	exit(EXIT_FAILURE);
}
