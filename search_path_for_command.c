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
            return exeArg;
        }

        free(exePath);
        exePath = token_(path, ":", &state);
    }

    params->status = 127;
    write_error_message(params, "not found\n");
    return NULL;
}
