#include "shell.h"

/**
 * search_path_for_command - Search for the command in the paths specified in PATH.
 * @path: The PATH environment variable.
 * @params: The parameters.
 *
 * Return: A string of the valid path to the command file, or NULL if not found.
 */
char *search_path_for_command(char *path, param_t *params)
{
    char *exePath = NULL, *exeArg = NULL, *tmp = NULL;
    char *state = NULL;

    exePath = token_(path, ":", &state);
    while (exePath)
    {
        tmp = exeArg;
        exeArg = str_concat(exePath, "/");
        free(tmp);
        tmp = exeArg;
        exeArg = str_concat(exeArg, params->args[0]);
        free(tmp);

        if (access(exeArg, F_OK) == 0)
        {
            return (exeArg);
        }

        write(STDERR_FILENO, "not found\n", strlen("not found\n"));

        free(exePath);
        exePath = token_(path, ":", &state);
    }

    params->status = 127;
    return (NULL);
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
        write(STDERR_FILENO, "Permission denied\n", strlen("Permission denied\n"));
    }

    return (NULL);
}
