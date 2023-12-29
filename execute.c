#include "main.h"
#include <sys/wait.h>
/**
 * execute - executes a command.
 * @args: arguments and command.
 * @filename: original command written by user. We used it,
 * because if file doesn't exist we return NULL to arg[0].
 * Return: status.
 */
int execute(char **args, char *filename, int *status)
{
	int child_pid;

	if (strcmp(filename, "exit") == 0)
		return(*status);
	if (args[0])
	{
		child_pid = fork();
		if (child_pid == -1)
			perror("Error:");
		else if (child_pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("Error");
				exit(127);
			}
		}
		else
		{
			wait(status);
			if (WIFEXITED(*status))
				*status = WEXITSTATUS(*status);
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", filename);
		*status = 127;
	}
	return (*status);
}
