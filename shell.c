#include "main.h"
#include <sys/types.h>
/**
 * main - Entry point.
 * Return: status. It can be either 127 or 0 currently.
 */
int main(void)
{
	int flag = 0, status = 0;
	char *input = NULL, *filename = NULL, *path = getenv("PATH");
	char *path_alt = NULL, **token_arr = NULL, **path_arr = NULL;
	size_t size = 0;

	if (path != NULL && path[0] != '\0')
		path_alt = strdup(path);
	if (path_alt)
		path_arr = token_parse(path_alt, ":");
	while (getline(&input, &size, stdin) != -1)
	{
		if (token_arr && token_arr[0] && flag)
			free(token_arr[0]);
		if (token_arr)
			free(token_arr);
		token_arr = token_parse(input, " \n\t");
		if (token_arr == NULL || token_arr[0] == NULL || token_arr[0][0] == '\0')
			continue;
		filename = token_arr[0];
		token_arr[0] = check_file(path_arr, token_arr[0], &flag);
		status = execute(token_arr, filename, &status);
		if (strcmp(filename, "exit") == 0)
			break;
	}
	if (token_arr && token_arr[0] && flag)
		free(token_arr[0]);
	if (token_arr)
		free(token_arr);
	if (path_arr)
		free(path_arr);
	free(path_alt);
	free(input);
	return (status);
}
