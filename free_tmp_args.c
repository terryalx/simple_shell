#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * free_tmp_args - Helper function to free memory allocated for tmpArgs array
 * @tmpArgs: Array of shell parameters
 * Return: void
 */
void free_tmp_args(char **tmpArgs)
{
	int i;

	for (i = 0; i < 3; i++)
	{
		free(tmpArgs[i]);
	}
	free(tmpArgs);
}
