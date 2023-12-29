#include "main.h"
/**
 * _printenv - prints environment.
 */
void _printenv()
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
