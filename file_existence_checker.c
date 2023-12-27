#include "main.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
/**
 * 
 */
char *check_file(char **path_arr, char *filepath)
{
	int i = 0;
	char *file_path = NULL, *slash = "/";
	struct stat st;

	if (stat(filepath, &st) == 0)
		return (filepath);
	else
	{
		while (path_arr[i] != NULL)
		{
			file_path = malloc(strlen(path_arr[i]) + strlen(filepath) + 2);
			if (file_path == NULL)
			{
				perror("Error: Can't allocate memory.");
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
	}
	free(file_path);
	return (NULL);
}
