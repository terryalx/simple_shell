#include "shell.h"

#include <unistd.h>
#include <stdlib.h>

/**
 * _cd - change current working directory
 * @params: shell parameters
 * Return: void
 */
char **create_tmp_args(param_t *params)
{
	char **tmpArgs = malloc(sizeof(char *) * 3);
	if (!tmpArgs)
		exit(-1);

	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("OLDPWD");
	tmpArgs[2] = _getenv("PWD", params);

	return tmpArgs;
}
