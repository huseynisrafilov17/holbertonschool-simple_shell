#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int execute(char **args, char *filename)
{
	int status = 0, child_pid;

	if (args[0])
	{
		child_pid = fork();
		if (child_pid == -1)
			perror("Error:");
		else if (child_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error");
				exit(127);
			}
		}
		else
			wait(&status);
	}
	else
	{
		dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", filename);
		status = 127;
	}
	return (status);
}
