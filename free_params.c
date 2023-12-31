#include "shell.h"

/**
 * free_params - Frees the memory allocated
 * for the param_t structure and its components.
 * @params: Pointer to the param_t structure.
 *
 * This function frees the memory allocated for
 * the param_t structure and its components, including
 * the buffer, nextCommand, environment list,
 * alias list, and arguments.
 *
 * @params: Pointer to the param_t structure
 * to be freed.
 */
void free_params(param_t *params)
{
	unsigned int i;

	if (params->buffer)
		free(params->buffer);
	if (params->nextCommand)
		free(params->nextCommand);
	free_list(params->env_head);
	free_list(params->alias_head);

	for (i = 0; params->args[i]; i++)
		free(params->args[i]);
	free(params->args);
	free(params);
}
