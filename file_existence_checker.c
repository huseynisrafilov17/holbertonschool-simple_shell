#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
/**
 * 
 */
int check_file(char *path, char *filepath)
{
	int flag = 0, i = 0;
	char **path_arr = token_parse(path, ":"), *file_path = NULL;
	struct stat st;

	if (stat(filepath, &st) == 0)
		return (1);
	else
	{
		while (path_arr[i])
		{
			file_path = strcat(path_arr[i], filepath);
			if (stat(file_path, &st) == 0)
				return (1);
			i++;
		}
	}
	return (0);
}
