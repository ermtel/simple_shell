#include "holberton.h"

/**
 * split_line - splits the input line into command and arguments.
 * @line: the line of string to be splitted.
 * Return: splitted string.
 */

char **split_line(char *line)
{
	char *token, **tokens;
	unsigned int bufsize, i = 0;

	line[_strlen(line) - 1] = '\0';
	bufsize = num_of_comms(line);
	if (bufsize == 0)
		return (NULL);
	tokens = malloc((bufsize + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, "Allocation Error\n", 16);
		free(tokens);
		return (NULL);
	}
	token = strtok(line, TOK_DELIM);

	for (i = 0; token != NULL; i++)
	{
		tokens[i] = malloc((_strlen(token) + 1) * sizeof(char));
		if (tokens[i] == NULL)
		{
			free_dbl_ptr(tokens);
			write(STDERR_FILENO, "Allocation Error\n", 16);
			return (NULL);
		}
		_memcpy(tokens[i], token, _strlen(token) + 1);
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	free(token);
	return (tokens);
}

/**
 * num_of_comms - returns the number of commands entered by the user.
 * @str: the commands entered by the user.
 * Return: the number of commands (arguments).
 */
unsigned int num_of_comms(char *str)
{
	unsigned int comms, i, flag;

	flag = 0;
	comms = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
			flag = 1;

		if ((flag && str[i + 1] == ' ') || (flag && str[i + 1] == '\0'))
		{
			++comms;
			flag = 0;
		}
	}
	return (comms);
}
