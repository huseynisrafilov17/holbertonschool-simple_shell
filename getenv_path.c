#include "main.h"
/**
 * _printenv - prints environment.
 */
void _printenv(void)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
