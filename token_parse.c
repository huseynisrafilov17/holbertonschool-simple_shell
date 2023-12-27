#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * delim_counter - counts deliminators in the str.
 * @str: string.
 * Return: deliminator count.
 */
int delim_counter(char *str, char *delim)
{
	int j = 0, i = 1, count = 1;

	while (str[i] != '\0')
	{
		while (delim[j] != '\0')
		{
			if ((str[i - 1] == delim[j]) && str[i] > 32)
			{
				count++;
				break;
			}
			j++;
		}
		i++;
	}
	return (count);
}
/**
 * token_parse - splits a string.
 * @str: string.
 * @delim: deliminators.
 * Return: pointer to the array of divided strings.
 */
char **token_parse(char *str, char *delim)
{
	int delim_count = delim_counter(str, delim);
	char **strarr = NULL;
	char *token = NULL;
	int token_number = 0;

	strarr = malloc((delim_count + 1) * sizeof(char *));
	if (strarr == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't allocate memory.");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, delim);
	while (token != NULL)
	{
		strarr[token_number] = token;
		token = strtok(NULL, " \n");
		token_number++;
	}
	strarr[token_number] = NULL;
	return (strarr);
}
