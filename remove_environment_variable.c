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
	list_t *prev = NULL, *h = params->env_head;

	if (params->tokCount != 2)
	{
		params->status = 0;
		return;
	}
	while (h)
	{
		if (string_compare(name, h->str) == 0)
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
