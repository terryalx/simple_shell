#include "shell.h"

#include <stdlib.h>

/**
 * _setenv - function searches list to environment variable name.
 * @params: parameters
 */
void _setenv(param_t *params)
{
	int val = 0;
	char *tmp = NULL;
	char *name = params->args[1];
	char *value = params->args[2];

	list_t *h = params->env_head;

	if (params->tokCount != 3)
	{
		params->status = 0;
		return;
	}
	while (h)
	{
		if (_strcmp(name, h->str) == 0)
		{
			tmp = h->val;
			free(tmp);
			h->val = _strdup(value);
			if (!h->val)
			{
				write(STDERR_FILENO, "setenv malloc error\n", 18);
				exit(val);
			}
			h->val_len = _strlen(value);
			params->status = 0;
			return;
		}
		h = h->next;
	}
	params->env_head = add_node(&(params->env_head), name, value);
	params->status = 0;
}
