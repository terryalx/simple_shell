#include "shell.h"

#include <unistd.h>
#include <stdlib.h>

/**
 * setenv_pwd - _cd helper
 * @tmpArgs: shell parameters
 * @cwd: ..
 * @params: ...
 * Return: void
 */
void setenv_pwd(char **tmpArgs, char *cwd, param_t *params)
{
	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("PWD");
	tmpArgs[2] = _strdup(getcwd(cwd, 1024));
	if (!tmpArgs[0] || !tmpArgs[1] || !tmpArgs[2])
	{
		write(STDERR_FILENO, "cd new PWD malloc error\n", 23);
		free_params(params);
		exit(-1);
	}
	_setenv(params);
	free_tmp_args(tmpArgs);
}
