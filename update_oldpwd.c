#include "shell.h"
#include <stdlib.h>
#include <limits.h>

/**
 * update_oldpwd - Update the value of the "OLDPWD" environment variable
 * @params: Pointer to the param_t struct
 *
 * This function updates the value of the "OLDPWD" environment variable
 * by setting it to the current working directory.
 */
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
