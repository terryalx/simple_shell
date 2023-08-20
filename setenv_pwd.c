#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * setenv_pwd - Set the PWD environment variable to the current working directory
 * @envArgs: Array of environment arguments
 * @currentWorkingDirectory: Current working directory
 * @shellParams: Pointer to the shell parameters struct
 *
 * This function sets the PWD environment variable to the current working directory.
 * It takes the environment arguments, current working directory, and a pointer to the shell parameters struct as arguments.
 * It uses the getcwd() function to get the current working directory and sets it as the value of the PWD environment variable.
 * If there is an error in allocating memory for the temporary arguments or setting the environment variable,
 * it prints an error message and exits the program.
 */
void setenv_pwd(char **envArgs, char *currentWorkingDirectory, param_t *shellParams)
{
	envArgs[0] = _strdup("setenv");
	envArgs[1] = _strdup("PWD");
	envArgs[2] = _strdup(getcwd(currentWorkingDirectory, 1024));
	if (!envArgs[0] || !envArgs[1] || !envArgs[2])
	{
		write(STDERR_FILENO, "cd new PWD malloc error\n", 23);
		free_params(shellParams);
		exit(-1);
	}
	_setenv(shellParams);
	free_tmp_args(envArgs);
}
