#include "shell.h"

/**
 * check_current_directory - check if command exists in the current directory
 * @params: parameters
 * Return: string of valid path to command file, NULL if not found
 * The string needs to be freed
 */
static char *check_current_directory(param_t *params)
{
    char *path = NULL;

    if (access(params->args[0], F_OK | X_OK) == 0)
    {
        free(path);
        return (str_duplicate(params->args[0]));
    }

    if (errno == EACCES)
    {
        params->status = 126;
        __write_error__(params, "Permission denied\n");
        return (NULL);
    }

    return (NULL);
}

/**
 * search_in_path - search for command in directories listed in PATH
 * @params: parameters
 * Return: string of valid path to command file, NULL if not found
 * The string needs to be freed
 */
static char *search_in_path(param_t *params)
{
    char *path = _getenv("PATH", params);
    char *exePath = NULL, *exeArg = NULL, *tmp = NULL;
    char *state = NULL;

    if (!path)
    {
        __write_error__(params, "not found\n");
        return (NULL);
    }

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
            free(path);
            free(exePath);
            return (exeArg);
        }

        free(exePath);
        exePath = token_(path, ":", &state);
    }

    params->status = 127;
    __write_error__(params, "not found\n");
    free(path);
    free(exePath);
    free(exeArg);
    return (NULL);
}

/**
 * get_file - get correct path to a command file
 * @params: parameters
 * Return: string of valid path to command file, NULL if not found
 * The string needs to be freed
 */
char *get_file(param_t *params)
{
    char *path;

    path = check_current_directory(params);
    if (path)
        return (path);

    return (search_in_path(params));
}
