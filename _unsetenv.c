#include "shell.h"

/**
 * _unsetenv - function searches the environment list to find the
 * environment variable name and removes it.
 * @params: parameters
*/

void _unsetenv(param_t *params)
{
	char *name = params->args[1];
	list_t *prev = NULL, *h = params->env_head;

	if (params->tokCount != 2)
	{
		params->status = 0;
		return;
	}
	while (h)
	{
		if (_strcmp(name, h->str) == 0) /* env var exists */
		{
			if (h == params->env_head)
				params->env_head = h->next_node;
			else
				prev->next_node = h->next_node;
			free(h->str);
			free(h->value);
			free(h);
			params->status = 0;
			return;
		}
		prev = h;
		h = h->next_node;
	}
	params->status = 0;
}
