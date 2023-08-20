#include "shell.h"

/**
 * _setenv - function searches list for environment variable name.
 * @params: parameters
 *
 * Return: void
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
		if (string_compare(name, h->str) == 0)
		{
			tmp = h->value;
			free(tmp);
			h->value = _strdup(value);
			if (!h->value)
			{
				write(STDERR_FILENO, "setenv malloc error\n", 18);
				exit(val);
			}
			h->value_length = _strlen(value);
			params->status = 0;
			return;
		}
		h = h->next_node;
	}

	params->env_head = add_node(&(params->env_head), name, value);
	params->status = 0;
}
