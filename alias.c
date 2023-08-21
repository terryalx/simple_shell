#include "shell.h"

/**
 * _alias - "alias" shell command.
 * @params: Pointer -> param_t struct.
 */

void _alias(param_t *params)
{
	unsigned int i;

	if (params->tokCount == 1)
	{
		print_all_aliases(params);
		return;
	}
	for (i = 1; i < params->tokCount; i++)
	{
		if (_strchr(params->args[i], '='))
		{
			set_alias(params->args[i], params);
		}
		else
		{
			print_alias(params->args[i], params);
		}
	}
}
