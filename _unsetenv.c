#include "shell.h"

/**
 * _unsetenv - Removes an environment variable from the list
 * @params: The parameters containing the environment list and variable name
 */
void _unsetenv(param_t *params)
{
	char *name = params->args[1];
	list_t *prev = NULL;
	list_t *current = params->env_head;

	if (params->tokCount != 2)
	{
		params->status = 0;
		return;
	}

	while (current)
	{
		if (string_compare(name, current->str) == 0)
		{
			if (current == params->env_head)
				params->env_head = current->next_node;
			else
				prev->next_node = current->next_node;

			free(current->str);
			free(current->value);
			free(current);
			params->status = 0;
			return;
		}

		prev = current;
		current = current->next_node;
	}

	params->status = 0;
}
