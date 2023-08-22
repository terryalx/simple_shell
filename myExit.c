#include "shell.h"

/**
 * myExit - built-in exit function
 * @params: parameters
 */
void myExit(param_t *params)
{
	int status = 0;
	char *arg = params->args[1];

	if (!arg)
	{
		status = params->status;
		free_params(params);
		exit(status);
	}
	
	if (validNum(arg))
	{
		status = string_to_int(arg);
		if (status == -1)
		{
			write_error_message(params, "Illegal number: ", arg);
			params->status = 2;
			return;
		}
		free_params(params);
		exit(status);
	}
	else
	{
		params->status = 2;
		write_error_message(params, "Illegal number: ", arg);
	}
}

/**
 * write_error_message - writes the error message to stderr
 * @params: parameters
 * @message: error message
 * @arg: argument causing the error
 */
void write_error_message(param_t *params, const char *message, const char *arg)
{
	__write_error__(params, message);
	write(STDERR_FILENO, arg, _strlen(arg));
	write(STDERR_FILENO, "\n", 1);
}
