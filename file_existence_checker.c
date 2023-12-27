#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
/**
 * 
 */
int check_file(char *path, char *filepath)
{
	int i = 0;
	char **path_arr, *file_path = NULL;
	struct stat st;

	if (stat(filepath, &st) == 0)
		return (1);
	else
	{
		path_arr = token_parse(path, ":\n");
		while (path_arr[i] != NULL)
		{
			file_path = strdup(path_arr[i]);
			strcat(file_path, filepath);
			if (stat(file_path, &st) == 0)
				return (1);
			printf("%s\n", path_arr[i]);
			i++;
		}
	}
	return (0);
}
