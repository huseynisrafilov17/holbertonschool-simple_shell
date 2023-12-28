#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void execute(char **args)
{
	if (args[0])
	{
		if (fork() == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(NULL);
	}
	else
		dprintf(STDERR_FILENO, "%s: not found.\n", args[0]);
}
