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
	char *input = NULL, **token_arr = NULL, **path_arr = token_parse(getenv("PATH"), ":");
	size_t size = 0;

	while (getline(&input, &size, stdin) != -1)
	{
		if (token_arr)
			free(token_arr);
		token_arr = token_parse(input, " \n\t");
		token_arr[0] = check_file(path_arr, token_arr[0]);
		if (token_arr[0])
		{
			if (fork() == 0)
			{
				if (execvp(token_arr[0], token_arr) == -1)
				{
					perror("Error: ");
					exit(EXIT_FAILURE);
				}
			}
			else
				wait(NULL);
		}
		else
			printf("File not found\n");
	}
	if (token_arr)
	{
		free(token_arr[0]);
		free(token_arr);
	}
	if (path_arr)
		free(path_arr);
	free(input);
	return (0);
}
