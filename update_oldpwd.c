#include "shell.h"
#include <stdlib.h>
#include <limits.h>

/*
 *
 * */

void update_oldpwd(param_t *params)
{
	char *currentWorkingDirectory;
	char **setenvArgs;

	currentWorkingDirectory = _getenv("PWD", params);
	if (!currentWorkingDirectory)
		return;

	setenvArgs = create_setenv_args("setenv", "OLDPWD", currentWorkingDirectory);
	if (!setenvArgs)
	{
		write(STDERR_FILENO, "cd old PWD malloc error\n", 23);
		free_params(params);
		return;
	}

	_setenv(params);
	free_tmp_args(setenvArgs);
}
