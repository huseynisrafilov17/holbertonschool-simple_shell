#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
/**
 * check_file - checks if a file exists and gives full path if it exists.
 * @path_arr: split PATH.
 * @filepath: command written by user.
 * @flag: We define behaviour of free in main function using this variable.
 * Return: string pointer to the full path.
 */
char *check_file(char **path_arr, char *filepath, int *flag)
{
	int i = 0;
	char *file_path = NULL, *slash = "/";
	struct stat st;

	if (stat(filepath, &st) == 0 && delim_counter(filepath, "/") != 0)
	{
		*flag = 0;
		return (filepath);
	}
	*flag = 1;
	while (path_arr != NULL && path_arr[i] != NULL)
	{
		file_path = malloc(strlen(path_arr[i]) + strlen(filepath) + 2);
		if (file_path == NULL)
		{
			dprintf(STDERR_FILENO, "Error: Can't allocate memory.");
			exit(EXIT_FAILURE);
		}
		strcpy(file_path, path_arr[i]);
		strcat(file_path, slash);
		strcat(file_path, filepath);
		if (stat(file_path, &st) == 0)
			return (file_path);
		free(file_path);
		i++;
	}
	return (NULL);
}
