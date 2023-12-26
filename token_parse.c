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
int delim_counter(char *str)
{
	int i = 1, count = 1;

	while (str[i] != '\0')
	{
		if ((str[i - 1] == ' ' || str[i - 1] == '\n' || str[i - 1] == '\t') && str[i] > 32)
			count++;
		i++;
	}
	return (count);
}
/**
 * token_parse - splits a string.
 * @str: string.
 * Return: pointer to the array of divided strings.
 */
char **token_parse(char *str)
{
	int delim_count = delim_counter(str);
	char **strarr = NULL;
	char *token = NULL;
	int token_number = 0;

	strarr = malloc(delim_count * sizeof(char *));
	if (strarr == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't allocate memory.");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, " \n\t");
	while (token != NULL)
	{
		strarr[token_number] = token;
		token = strtok(NULL, " \n");
		token_number++;
	}
	return (strarr);
}
