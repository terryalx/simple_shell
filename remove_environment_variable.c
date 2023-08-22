#include "shell.h"

/**
 * remove_environment_variable - Remove an environment variable from the list.
 * @params: Pointer to the param_t structure.
 *
 * This function removes an environment variable from the list based on the provided variable_name.
 * If the variable is found and removed, the status in the param_t structure is set to 0.
 *
 * @params: Pointer to the param_t structure containing the list of environment variables.
 */
void remove_environment_variable(param_t *params)
{
	char *variable_name = params->args[1];
	list_t *prev_node = NULL, *current_node = params->env_head;

	if (params->tokCount != 2)
	{
		params->status = 0;
		return;
	}
	while (current_node)
	{
		if (string_compare(variable_name, current_node->str) == 0)
		{
			if (current_node == params->env_head)
				params->env_head = current_node->next_node;
			else
				prev_node->next_node = current_node->next_node;
			free(current_node->str);
			free(current_node->value);
			free(current_node);
			params->status = 0;
			return;
		}
		prev_node = current_node;
		current_node = current_node->next_node;
	}
	params->status = 0;
}
