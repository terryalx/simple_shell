#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * restore_original_args - Restore original arguments
 * @params: Pointer to the param_t structure
 * @originArgs: Pointer to the original arguments
 *
 * This function restores the original arguments passed to the shell
 * by assigning the originArgs to the args member of the params structure.
 */
void restore_original_args(param_t *params, char **originArgs)
{
	params->args = originArgs;
}
