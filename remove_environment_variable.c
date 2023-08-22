#include "shell.h"

/**
 * remove_environment_variable - Remove an environment variable from the list.
 * @params: Pointer to the param_t structure.
 *
 * This function removes an environment variable from the list based on the provided name.
 * If the variable is found and removed, the status in the param_t structure is set to 0.
 *
 * @params: Pointer to the param_t structure containing the list of environment variables.
 */
void remove_environment_variable(param_t *params)
{
	char *name = params->args[1];
	list_t *prev = NULL, *current = params->env_head;

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
