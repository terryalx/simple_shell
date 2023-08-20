#include "shell.h"

/**
 * check_current_directory - Check if the command is executable in the current directory.
 * @params: The parameters.
 *
 * Return: A string of the valid path to the command file, or NULL if not found.
 */
char *check_current_directory(param_t *params)
{
    if (access(params->args[0], F_OK | X_OK) == 0)
    {
        return str_duplicate(params->args[0]);
    }

    if (errno == EACCES)
    {
        params->status = 126;
        write_error(params, "Permission denied\n");
    }

    return NULL;
}
