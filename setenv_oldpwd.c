#include "shell.h"

#include <unistd.h>
#include <stdlib.h>

/**
 * _cd - change current working directory
 * @params: shell parameters
 * Return: void
 */
void setenv_oldpwd(char *pwd, param_t *params)
{
	char **tmpArgs = malloc(sizeof(char *) * 3);
	if (!tmpArgs)
	{
		write(STDERR_FILENO, "cd old PWD malloc error\n", 23);
		free_params(params);
		exit(-1);
	}
	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("OLDPWD");
	tmpArgs[2] = pwd;
	_setenv(params);
	free_tmp_args(tmpArgs);
}
