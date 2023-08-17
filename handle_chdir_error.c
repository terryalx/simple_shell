#include "shell.h"

#include <unistd.h>
#include <stdlib.h>

/**
 * handle_chdir_error - _cd helper
 * @params: shell parameters
 * Return: void
 */
void handle_chdir_error(param_t *params, char *target)
{
	write_error(params, "can't cd to ");
	write(STDERR_FILENO, target, _strlen(target));
	write(STDERR_FILENO, "\n", 1);
	params->status = 0;
	free(target);
}
