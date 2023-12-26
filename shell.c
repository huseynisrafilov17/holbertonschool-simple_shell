#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
/*
 * main - Entry point.
 * @argc: argument count.
 * @argv: arguments.
 * Return: 0 on success.
 */
int main(void)
{
	char *str = NULL;
	char **strarr = NULL;
	size_t size = 0;

	while (getline(&str, &size, stdin) != EOF)
	{
		if (strarr)
			free(strarr);
		strarr = token_parse(str);
		if (fork() == 0)
			if (strarr[0] != NULL)
				execve(strarr[0], strarr, NULL);
		else
			wait(NULL);
	}
	if (strarr)
		free(strarr);
	free(str);
	return (0);
}
