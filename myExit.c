#include "shell.h"

/**
 * _myExit - Exit the shell
 * @parameters: The parameters passed to the function
 *
 * This function handles the exit command in the shell. It checks if an argument is provided
 * and if it is a valid number. If the argument is a valid number, it converts it to an integer
 * and exits with that status. If the argument is not a valid number, it displays an error message
 * and sets the status to 2. If no argument is provided, it exits with the current status.
 */
void _myExit(param_t *params)
{
	int status = 0;

	if (!params->args[1])
	{
		status = params->status;
		free_params(params);
		exit(status);
	}
	if (validNum(params->args[1]))
	{
		status = _atoi((params->args)[1]);
		if (status == -1)
		{
			write_error(params, "Illegal number: ");
			write(STDERR_FILENO, params->args[1],
			      _strlen(params->args[1]));
			write(STDERR_FILENO, "\n", 1);
			params->status = 2;
			return;
		}
		free_params(params);
		exit(status);
	}
	else
	{
		params->status = 2;
		write_error(params, "Illegal number: ");
		write(STDERR_FILENO, params->args[1],
		      _strlen(params->args[1]));
		write(STDERR_FILENO, "\n", 1);
	}
}
