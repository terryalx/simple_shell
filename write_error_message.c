#include "shell.h"

/**
 * write_error_message - Write an error message to stderr.
 * @params: The parameters.
 * @message: The error message to write.
 */
void write_error_message(param_t *params, const char *message)
{
    write(STDERR_FILENO, message, strlen(message));
}

/**
 * check_current_directory - Check if the command is executable in the current directory.
 * @params: The parameters.
 *
 * Return: A string of the valid path to the command file, or NULL if not found.
 */
char *check_current_directory(param_t *params)
{
    char *command_path = params->args[0];

    if (access(command_path, F_OK | X_OK) == 0)
    {
        return (str_duplicate(command_path));
    }

    if (access(command_path, F_OK) == 0)
    {
        params->status = 126;
        write_error_message(params, "Permission denied\n");
    }

    return (NULL);
}