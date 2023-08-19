#include "shell.h"
#include <stdlib.h>
#include <limits.h>

/*
 *
 *
 *
 *
 *
 *
 * */

char **create_setenv_args(char *command, char *variable, char *value)
{
	char **setenvArgs = malloc(sizeof(char *) * 4);
	if (!setenvArgs)
		return NULL;

	setenvArgs[0] = _strdup(command);
	setenvArgs[1] = _strdup(variable);
	setenvArgs[2] = _strdup(value);
	setenvArgs[3] = NULL;

	if (!setenvArgs[0] || !setenvArgs[1] || !setenvArgs[2])
	{
		free_tmp_args(setenvArgs);
		return NULL;
	}

	return setenvArgs;
}
