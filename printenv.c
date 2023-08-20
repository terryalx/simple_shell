#include "shell.h"

/**
 * _printenv - prints environment
 * @params: parameters
 * 
 * Return: void
 */
void _printenv(param_t *params)
{
	if (params->tokCount != 1)
	{
		_printf("env: %s: No such file or directory\n",
			params->args[1]);
		params->status = 2;
		return;
	}
	print_list_env(params->env_head);
	params->status = 0;
}
