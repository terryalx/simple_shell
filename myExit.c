#include "shell.h"
#include <stdlib.h>
#include <limits.h>

/**
 * _myExit - Exit the shell
 * @parameters: The parameters passed to the function
 *
 * This function handles the exit command in the shell. It checks if an argument is provided
 * and if it is a valid number. If the argument is a valid number, it converts it to an integer
 * and exits with that status. If the argument is not a valid number, it displays an error message
 * and sets the status to 2. If no argument is provided, it exits with the current status.
 */
void _myExit(param_t *parameters)
{
	if (!parameters->args[1])
	{
		int status = parameters->status;
		free_params(parameters);
		exit(status);
	}

	if (is_valid_number(parameters->args[1]))
	{
		int status = _atoi(parameters->args[1]);
		if (status == -1)
		{
			write_error(parameters, "Illegal number: ");
			write(STDERR_FILENO, parameters->args[1], _strlen(parameters->args[1]));
			write(STDERR_FILENO, "\n", 1);
			parameters->status = 2;
			return;
		}
		free_params(parameters);
		exit(status);
	}
	else
	{
		parameters->status = 2;
		write_error(parameters, "Illegal number: ");
		write(STDERR_FILENO, parameters->args[1], _strlen(parameters->args[1]));
		write(STDERR_FILENO, "\n", 1);
	}
}
