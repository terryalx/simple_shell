#include "shell.h"

#include <unistd.h>
#include <stdlib.h>

/**
 * restore_original_args - _cd helper
 * @params: shell parameters
 * Return: void
 */
void restore_original_args(param_t *params, char **originArgs)
{
	params->args = originArgs;
}
