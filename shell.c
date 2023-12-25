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
int main(int argc, char *argv[])
{
	int i = 0;
	char *str;
	char **strarr;
	size_t size = 0;
	printf("$ ");
	while (getline(&str, &size, stdin) != EOF)
	{
		strarr = token_parse(str);
		printf("$ ");
		if (fork() == 0)
		{
			execve(strarr[0], strarr, NULL);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
