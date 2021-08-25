#include "holberton.h"

/**
 * execute - executes a shell program.
 * @argv: the argument vector from main function.
 * @buffer: the line entered by the user using  getline.
 * @comm: the commands string vector.
 * @count: the number of times a command is executed.
 * Return: the status of the execution.
 */

int execute(char **argv, char *buffer, char **comm, int count)
{
	pid_t child_pid;
	int status, i;
	struct stat filestat, filestat2;
	char *exit_com = "exit", *env_com = "env", **all_dir;

	child_pid = fork();
	if (child_pid == -1)
		fork_fail();
	if (child_pid == 0)
	{
		if (comm == NULL)
			comm_null(buffer);
		else if (_strcmp(exit_com, comm[0]) == 0)
			shell_exit(buffer, comm, environ);
		else if (_strcmp(env_com, comm[0]) == 0)
			print_env(buffer, comm, environ);
		else if (stat(comm[0], &filestat) == 0)
			execve(comm[0], comm, NULL);
		else
		{
			all_dir = store_path_command(comm[0]);
			for (i = 0; all_dir[i] != NULL; i++)
				if (stat(all_dir[i], &filestat2) == 0)
					execve(all_dir[i], comm, NULL);
			error_mess(argv, comm, count);
			free_buf_n_comm(buffer, comm);
			free_dbl_ptr(all_dir);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (comm == NULL)
			free_buf_n_comm(buffer, comm);
		else if (_strcmp(exit_com, comm[0]) == 0)
			shell_exit(buffer, comm, environ);
		else
			free_buf_n_comm(buffer, comm);
	} return (1);
}
