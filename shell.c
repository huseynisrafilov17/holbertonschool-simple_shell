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
	char *value = getenv("PATH"), *input = NULL, **token_arr = NULL;
	size_t size = 0;

	while (getline(&input, &size, stdin) != EOF)
	{
		if (token_arr)
			free(token_arr);
		token_arr = token_parse(input, " \n\t");
		if (check_file(value, token_arr[0]) == 1)
		{
			if (fork() == 0)
			{
				if (token_arr[0] != NULL) /*should be executable*/
					execvp(token_arr[0], token_arr);
			}
			else
				wait(NULL);
		}
		else
			printf("File not found\n");
	}
	if (token_arr)
		free(token_arr);
	free(input);
	return (0);
}
