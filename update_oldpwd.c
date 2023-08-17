#include "shell.h"

#include <unistd.h>
#include <stdlib.h>

/**
 * update_oldpwd - _cd helper
 */
void update_oldpwd(param_t *params)
{
	char *oldpwd;
	char *tmpArgs[3];

	oldpwd = _getenv("PWD", params);
	if (!oldpwd)
		return;

	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("OLDPWD");
	tmpArgs[2] = _strdup(oldpwd);
	if (!tmpArgs[0] || !tmpArgs[1] || !tmpArgs[2])
	{
		write(STDERR_FILENO, "cd old PWD malloc error\n", 23);
		free_params(params);
		exit(-1);
	}

	_setenv(params);
	free_tmp_args(tmpArgs);
}
