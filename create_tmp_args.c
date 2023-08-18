#include "shell.h"

#include <unistd.h>
#include <stdlib.h>

/**
 * create_tmp_args - _cd helper
 * @params: shell parameters
 * Return: void
 */
char **create_tmp_args(param_t *params)
{
	int vall = -1;

	char **tmpArgs = malloc(sizeof(char *) * 3);

	if (!tmpArgs)
	{
		exit(vall);
	}

	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("OLDPWD");
	tmpArgs[2] = _getenv("PWD", params);

	return (tmpArgs);
}
