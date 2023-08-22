#include "shell.h"

/**
 * myExit - built-in exit function
 * @params: parameters
 */
void myExit(param_t *params)
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
		status = string_to_int((params->args)[1]);
		if (status == -1)
		{
			__write_error__(params, "Illegal number: ");
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
		__write_error__(params, "Illegal number: ");
		write(STDERR_FILENO, params->args[1],
				_strlen(params->args[1]));
		write(STDERR_FILENO, "\n", 1);
	}
}
