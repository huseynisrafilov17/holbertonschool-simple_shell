#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void execute(char **args, char *filename)
{
	int status;
	if (args[0])
	{
		if (fork() == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error");
				exit(status);
			}
		}
		else
			wait(&status);
	}
	else
	{
		dprintf(STDERR_FILENO, "./hsh: 1: %s: not found.\n", filename);
		exit(status);
	}
}
