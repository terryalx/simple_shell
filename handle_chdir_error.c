#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * handle_chdir_error - Helper function for _cd
 * @params: Shell parameters
 * @target: Target directory
 *
 * This function handles the error when changing the directory using the _cd command.
 * It prints an error message to stderr and updates the shell status.
 */
void handle_chdir_error(param_t *params, char *target)
{
	write_error(params, "can't cd to ");
	write(STDERR_FILENO, target, _strlen(target));
	write(STDERR_FILENO, "\n", 1);
	params->status = 0;
	free(target);
}
