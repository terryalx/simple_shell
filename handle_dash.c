#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * handle_dash - Helper function for the _cd command
 * @params: Shell parameters
 *
 * This function handles the "-" option for the _cd command. If the argument
 * is "-", it changes the current directory to the previous directory (OLDPWD).
 * If the argument is not "-", it prints an error message.
 */
void handle_dash(param_t *params)
{
	if (_strcmp(params->args[1], "-") == 0)
	{
		char *target = _getenv("OLDPWD", params);
		if (target == NULL)
		{
			params->status = 0;
			target = _getenv("PWD", params);
			_printf("%s\n", target);
			free(target);
			return;
		}
		_printf("%s\n", target);
		free(target);
	}
	else
	{
		params->status = 2;
		_printf("%s: %d: cd: Illegal option %c%c\n",
				params->argv[0], params->lineCount,
				'-', params->args[1][1]);
	}
}
