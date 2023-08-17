#include "shell.h"

#include <unistd.h>
#include <stdlib.h>

/**
 * handle_dash - _cd helper
 * @params: shell parameters
 * Return: void
 */
void handle_dash(param_t *params)
{
	if (!_strcmp(params->args[1], "-"))
	{
		char *target = _getenv("OLDPWD", params);
		if (!target)
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
