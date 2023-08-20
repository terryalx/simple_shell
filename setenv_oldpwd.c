#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * setenv_oldpwd - Sets the value of the OLDPWD environment variable
 * @pwd: The current working directory
 * @params: The shell parameters
 *
 * This function sets the value of the OLDPWD environment variable to the
 * current working directory.
 *
 * Return: void
 */
void setenv_oldpwd(char *pwd, param_t *params)
{
	int numArgs = 3;
	char **envArgs = malloc(sizeof(char *) * (numArgs + 1));

	if (!envArgs)
	{
		write(STDERR_FILENO, "Error: Failed to allocate memory for environment arguments\n", 60);
		free_params(params);
		return;
	}

	envArgs[0] = _strdup("setenv");
	envArgs[1] = _strdup("OLDPWD");
	envArgs[2] = pwd;
	envArgs[3] = NULL;

	_setenv(params);

	free_tmp_args(envArgs);
}
