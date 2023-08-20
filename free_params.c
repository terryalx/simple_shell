#include "shell.h"
#include <stdlib.h>

/**
 * free_params - Frees the memory allocated for the param_t structure.
 * @param: pointer to the param_t structure
 *
 * Description:
 *     This function frees the memory allocated for the param_t structure.
 *     It takes a pointer to the param_t structure as a parameter.
 *     The structure contains various fields such as buffer, nextCommand,
 *     env_head, alias_head, and args.
 */
void free_params(param_t *param)
{
	unsigned int index;

	if (param->buffer)
		free(param->buffer);

	if (param->nextCommand)
		free(param->nextCommand);

	free_list(param->env_head);
	free_list(param->alias_head);

	for (index = 0; param->args[index]; index++)
		free(param->args[index]);

	free(param->args);
	free(param);
}
