#include "shell.h"
#include <stdlib.h>

/**
 * _setenv - function searches the environment list to find the
 * environment variable name, and sets to the corresponding
 * value string.
 * @params: parameters
*/

void _setenv(param_t *params)
{
	char *tmp = NULL;
	char *name = params->args[1], *value = params->args[2];
	list_t *h = params->env_head;

	if (params->tokCount != 3)
	{
		params->status = 0;
		return;
	}
	while (h)
	{
		if (_strcmp(name, h->str) == 0) /* env var exists */
		{
			tmp = h->val;
			free(tmp);
			h->val = _strdup(value);
			if (!h->val)
			{
				write(STDERR_FILENO, "setenv malloc error\n", 18);
				exit(-1);
			}
			h->val_len = _strlen(value);
			params->status = 0;
			return;
		}
		h = h->next;
	}
	/* env var DNE */
	params->env_head = add_node(&(params->env_head), name, value);
	params->status = 0;
}
