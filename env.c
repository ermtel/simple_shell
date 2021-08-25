#include "holberton.h"

/**
 * _getenv - searches the environment list to find @name and
 *           returns a pointer to the corresponding value string.
 * @name: the name of the enviromental variable to look for.
 * @environ: the environmental variables.
 * Return: the value of the environmental variable or NULL if not found.
 */

char *_getenv(const char *name, char **environ)
{
	char *env_value;
	unsigned int len, i = 0;

	len = _strlen(name);
	env_value = strtok(environ[i], "=");
	while (environ[i])
	{
		if (_strncmp(env_value, name, len) == 0)
		{
			env_value = strtok(NULL, "\n");
			return (env_value);
		}
		i++;
		env_value = strtok(environ[i], "=");
	}
	return (NULL);
}
/**
 * appcmd - append the command with / and the path.
 *
 * @envcmd: the environmental command to be returned.
 * @envdir: the path to be appended with the @command.
 * @command: the command entered.
 * Return: the appended command @envcmd.
 */
char *appcmd(char *envcmd, char *envdir, char *command)
{
	int i, j, comm_len;

	for (i = 0; envdir[i] != '\0'; i++)
		envcmd[i] = envdir[i];
	envcmd[i] = '/';
	i++;

	comm_len = _strlen(command);
	for (j = 0; j < comm_len && command[j] != '\0'; j++, i++)
		envcmd[i] = command[j];
	envcmd[i] = '\0';

	return (envcmd);
}
/**
 * num_dir - counts the number of directories in the PATH.
 * @path: the PATH
 * Return: the number of directories.
 */
unsigned int num_dir(char *path)
{
	unsigned int i, count = 0;

	for (i = 0; path[i]; i++)
	{
		if (path[i] != ':')
		{
			if ((path[i + 1] == ':') || (path[i + 1] == '\0'))
				count++;
		}
	}
	return (count);
}
/**
 * store_path_command - stores the commands appended to the PATH directory.
 * @first_com: the first argument entered by the user as a command.
 * Return: a pointer to the directories in the PATH.
 */

char **store_path_command(char *first_com)
{
	char **all_directories, *path_env, *directory;
	unsigned int length, i;
	int dir_l, com_l;

	path_env = _getenv("PATH", environ);
	length = num_dir(path_env);
	all_directories = malloc(sizeof(char *) * (length + 1));
	if (all_directories == NULL)
		return (NULL);

	i = 0;
	directory = strtok(path_env, ":");
	while (directory != NULL)
	{
		dir_l = _strlen(directory);
		com_l = _strlen(first_com);
		all_directories[i] = malloc(sizeof(char) * (dir_l + com_l + 2));
		if (all_directories[i] == NULL)
		{
			free_dbl_ptr(all_directories);
			return (NULL);
		}

		appcmd(all_directories[i], directory, first_com);

		++i;
		directory = strtok(NULL, ":");
	}
	all_directories[i] = NULL;

	return (all_directories);
}
