#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
/**
 * 
 */
char *check_file(char **path_arr, char *filepath)
{
	int i = 0;
	char *file_path = NULL;
	struct stat st;

	if (stat(filepath, &st) == 0)
		return (filepath);
	else
	{
		while (path_arr[i] != NULL)
		{
			file_path = strdup(path_arr[i]);
			strcat(file_path, "/");
			strcat(file_path, filepath);
			if (stat(file_path, &st) == 0)
				return (file_path);
			i++;
		}
	}
	return (NULL);
}
